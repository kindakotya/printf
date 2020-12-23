# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/24 02:08:10 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =										ft_printf.c\
													printf_conv_csdi.c\
													printf_utils.c\

HEAD = libftprintf.h

OBJS = $(SRCS:.c=.o)

MAKEFILES = ./libft/Makefile

.Phony: all $(NAME) %.o clean fclean re



all: $(NAME)

$(NAME): $(MAKEFILES) $(OBJS) main.c
	ar rc $(NAME) $(OBJS)
	clang -g -Wall -Werror -Wextra main.c -o printf -L. libftprintf.a ./libft/libft.a

$(MAKEFILES): force
	make -f $(MAKEFILES)

force: ;

%.o : %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -c $<

.DEFAULT:clean:
	make clean -f $(MAKEFILES)
	rm -rf $(OBJS)

fclean: clean
	make fclean -f $(MAKEFILES)
	rm -rf $(NAME) printf

re: fclean $(NAME)