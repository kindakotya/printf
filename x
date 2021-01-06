	$(MAKE) printf

printf:
	gcc -g -Wall -Werror -Wextra main.c -o printf -L. libftprintf.a ./libft/libft.a