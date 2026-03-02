FLAGS = -Werror -Wall -Wextra -lncurses
USER_FLAGS = -lncurses

full_recompilation:
	gcc $(FLAGS) -c src/menu.c -o src/menu.o
	@echo "Compiling full application"

user_recompilation:
	@gcc $(USER_FLAGS) -c src/menu.c -o src/menu.o
	@#echo "Compiling full application"

clean: 
	@rm src/menu.o

full: full_recompilation
	@gcc  src/menu.o -o arch-center $(FLAGS)

archc: user_recompilation
	@gcc src/menu.o -o arch-center $(FLAGS)
