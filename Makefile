FLAGS = -Wall -Wextra -lncurses -Werror
USER_FLAGS = -lncurses
ZIG_FLAGS = -Wall -Wextra -lncurses -pedantic -fsanitize=undefined -Werror

menu = src/menu.c -o src/menu.o
functions = src/functions.c -o src/functions.o
programs = src/programs.c -o src/programs.o
submenu = src/submenu.c -o src/submenu.o

full_recompilation:
	gcc $(FLAGS) -c $(menu)
	gcc $(FLAGS) -c $(function)
	gcc $(FLAGS) -c $(programs)
	gcc $(FLAGS) -c $(submenu)
	@echo "Compiling full application"

user_recompilation:
	@gcc $(USER_FLAGS) -c $(menu)
	@gcc $(USER_FLAGS) -c $(function)
	@gcc $(USER_FLAGS) -c $(programs)
	@gcc $(USER_FLAGS) -c $(submenu)

zig_recompilation:
	zig cc $(ZIG_FLAGS) -c $(menu)
	zig cc $(ZIG_FLAGS) -c $(function)
	zig cc $(ZIG_FLAGS) -c $(programs)
	zig cc $(ZIG_FLAGS) -c $(submenu)

clean: 
	@rm src/menu.o
	@rm src/functions.o
	@rm src/programs.o
	@rm src/submenu.o

archc: user_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)

arch-center: user_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)


full: full_recompilation
	@gcc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)

zigg: zig_recompilation
	@zig cc src/programs.o src/submenu.o src/functions.o src/menu.o -o arch-center $(FLAGS)

