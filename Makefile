FLAGS = -Werror -Wall -Wextra

full_recompilation:
	gcc $(FLAGS) -c src/menu.c -o src/menu.o
	@echo "Compiling full application"

clean: 
	@rm menu.o

full: full_recompilation
	gcc $(FLAGS) src/menu.o -o arch-center
