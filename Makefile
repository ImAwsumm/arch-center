FLAGS = -Werror -Wall -Wextra

full_recompilation:
	gcc $(FLAGS) -c menu.c
	@echo "Compiling full application"

clean: 
	@rm menu.o

full: full_recompilation
	gcc $(FLAGS) menu.o -o arch-center
