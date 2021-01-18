# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2021/01/18 13:54:45 by gmayweat         ###   ########.fr        #
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

.Phony: all $(NAME) clean fclean re libft.a $(OBJDIR)

all: libft.a $(NAME)

libft.a:
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(addprefix obj/, $(OBJS))
	ranlib $(NAME)

%.o : %.c $(HEAD)
	gcc -Wall -Wextra -Werror -I. -Ilibft -o $(patsubst src/%, obj/%, $(patsubst %.c, %.o, $<)) -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJDIR)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(OBJDIR) $(NAME)

re: fclean all