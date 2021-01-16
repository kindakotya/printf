# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2021/01/16 22:33:21 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/libft.a

SRCS =					ft_printf.c\
						printf_conv.c\
						printf_comm_utils.c\
						printf_spec_utils.c\
						ft_dextohex.c

HEAD = libftprintf.h

OBJS = $(SRCS:.c=.o)

OBJDIR = obj

vpath %.o obj
vpath %.c src

.Phony: all $(NAME) clean fclean re libft.a

all: libft.a $(NAME)

libft.a:
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS) main.c
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(addprefix obj/, $(OBJS))
	ranlib $(NAME)
	gcc -g main.c -o printf -L. libftprintf.a
#-Wall -Werror -Wextra

%.o : %.c $(HEAD)
	gcc -g -Wall -Wextra -Werror -o $(patsubst src/%, obj/%, $(patsubst %.c, %.o, $<)) -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(OBJDIR) $(NAME) printf

re: fclean all