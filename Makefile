# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/25 14:48:39 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS =					ft_printf.c\
						printf_conv_csdi.c\
						printf_utils.c\
						ft_dextohex.c

HEAD = libftprintf.h

OBJS = $(SRCS:.c=.o)

.Phony: all $(NAME) %.o clean fclean re libft.a

all: libft.a $(NAME)

$(NAME): $(LIBFT) $(OBJS) main.c
	ar rc $(NAME) $(OBJS)
	clang -g -Wall -Werror -Wextra main.c -o printf -L. libftprintf.a ./libft/libft.a

libft.a:
	$(MAKE) -C libft

%.o : %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -c $<

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(OBJS) $(NAME) printf

re: fclean all