FLAGS = -Wall -Wextra -lncurses
USER_FLAGS = -lncurses

full_recompilation:
	gcc $(FLAGS) -c src/menu.c -o src/menu.o
	gcc $(FLAGS) -c src/functions.c -o src/functions.o
	@echo "Compiling full application"

user_recompilation:
	@gcc $(USER_FLAGS) -c src/menu.c -o src/menu.o
	@gcc $(USER_FLAGS) -c src/functions.c -o src/functions.o

clean: 
	@rm src/menu.o
	@rm src/functions.o

archc: user_recompilation
	@gcc src/functions.o src/menu.o -o arch-center $(FLAGS)

arch-center: user_recompilation
	@gcc src/functions.o src/menu.o -o arch-center $(FLAGS)


full: full_recompilation
	@gcc src/functions.o src/menu.o -o arch-center $(FLAGS)

