FLAGS = -Wall -Wextra -lncurses
USER_FLAGS = -lncurses

full_recompilation:
	gcc $(FLAGS) -c src/menu.c -o src/menu.o
	gcc $(FLAGS) -c src/functions.c -o src/functions.o
	gcc $(FLAGS) -c src/programs.c -o src/programs.o
	gcc $(FLAGS) -c src/submenu.c -o src/submenu.o
	@echo "Compiling full application"

user_recompilation:
	@gcc $(USER_FLAGS) -c src/menu.c -o src/menu.o
	@gcc $(USER_FLAGS) -c src/functions.c -o src/functions.o
	@gcc $(USER_FLAGS) -c src/programs.c -o src/programs.o
	@gcc $(USER_FLAGS) -c src/submenu.c -o src/submenu.o

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

