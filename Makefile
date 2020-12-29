# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/29 14:50:03 by gmayweat         ###   ########.fr        #
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

OBJDIR = obj

OBJSPATH = $(addprefix obj/, $(OBJS))

vpath %.o obj
vpath %.c src

.Phony: all $(NAME) clean fclean re libft.a

all: libft.a $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS) main.c
	ar rc $(NAME) $(OBJSPATH)
	clang -g -Wall -Werror -Wextra main.c -o printf -L. libftprintf.a ./libft/libft.a

libft.a:
	$(MAKE) -C libft

%.o : %.c $(HEAD)
	clang -g -Wall -Wextra -Werror -o $(patsubst src/%, obj/%, $(patsubst %.c, %.o, $<)) -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(OBJDIR) $(NAME) printf

re: fclean all