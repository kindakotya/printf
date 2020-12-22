# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/22 01:22:33 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =										ft_printf.c\
													printf_conv_csdi.c\
													printf_utils.c\

HEAD = libftprintf.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) main.c
	make -C ./libft/
	ar rc $(NAME) $(OBJS)
	clang -g -Wall -Werror -Wextra main.c -o printf -L. libftprintf.a ./libft/libft.a

%.o : %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -c $<

clean:
	make clean -C ./libft/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME) printf

re: fclean $(NAME)