# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/17 18:31:55 by gmayweat          #+#    #+#              #
#    Updated: 2020/12/24 21:16:32 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =										ft_printf.c\
													printf_conv_csdi.c\
													printf_utils.c\

HEAD = libftprintf.h

OBJS = $(SRCS:.c=.o)

.Phony: all $(NAME) %.o clean fclean re libft.a

all: $(NAME) libft.a

$(NAME): $(OBJS) main.c
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

re: fclean $(NAME)