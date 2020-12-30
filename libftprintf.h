/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:43:54 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/30 11:12:05 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

#define LIBFTPRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

int			ft_printf(const char *s, ...);
ssize_t		ft_putchar(char *sub, va_list args);
ssize_t		ft_putstr(const char *sub, va_list args);
ssize_t		ft_putint(const char *sub, va_list args, char conv);
ssize_t		ft_putuint(const char *sub, va_list args);
ssize_t		ft_putpoint(const char *sub, va_list args);
ssize_t		ft_printnchars(size_t n, char c);
size_t		ft_flagcheck(const char *sub, va_list args, size_t *acc);
ssize_t		ft_printposnbr(const char *sub, const char *s, size_t width, size_t acc);
ssize_t		ft_printnegnbr(const char *sub, const char *s, size_t width, size_t acc);
char		*ft_addplus(char **s);
char		*ft_dextohex(long int n, char conv);

#endif