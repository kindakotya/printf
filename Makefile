# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/28 09:29:22 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS =					ft_printf.c\
						printf_conv.c\
						printf_utils.c\
						ft_dextohex.c

HEAD = libftprintf.h

OBJS = $(SRCS:.c=.o)

OBJSPATH = $(addprefix objs/, $(OBJS))

vpath %.o objs

.Phony: all $(NAME) %.o clean fclean re libft.a

all: libft.a $(NAME)

$(NAME): $(LIBFT) $(OBJS) main.c
	ar rc $(NAME) $(OBJSPATH)
	clang -g -Wall -Werror -Wextra main.c -o printf -L. libftprintf.a ./libft/libft.a

libft.a:
	$(MAKE) -C libft

%.o : %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -o $(addprefix objs/, $(patsubst %.c, %.o, $<)) -c $<

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJSPATH)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(OBJSPATH) $(NAME) printf

re: fclean all