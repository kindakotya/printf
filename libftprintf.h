/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:43:54 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/10 20:46:33 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_struct
{
	int		is_width;
	ssize_t width;
	int		is_acc;
	ssize_t acc;
	int		is_minus;
	int		is_zero;
	int		n_sym;
	va_list args;
}				t_struct;

int			ft_printf(const char *s, ...);
ssize_t		ft_putchar(char *sub, va_list args, char conv);
ssize_t		ft_putstr(const char *sub, va_list args);
ssize_t		ft_putint(const char *sub, va_list args, char conv);
ssize_t		ft_putuint(const char *sub, va_list args);
ssize_t		ft_putpoint(const char *sub, va_list args);
ssize_t		ft_printnchars(size_t n, char c, ssize_t *width);
ssize_t		ft_flagcheck(const char *sub, va_list args, ssize_t *acc);
ssize_t		ft_printposnbr(const char *sub, const char *s,
	ssize_t width, ssize_t acc);
ssize_t		ft_printnegnbr(const char *sub, const char *s,
	ssize_t width, ssize_t acc);
char		*ft_bonusflags(const char *sub, char **s, char conv);
char		*ft_dextohex(long int n, char conv);

#endif
