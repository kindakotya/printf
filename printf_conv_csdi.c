/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_csdi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:30:14 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/24 01:00:47 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


ssize_t		ft_putchar(char *sub, va_list args)
{
	ssize_t n;
	char 		c;
	int 		i;

	n = 1;
	if (sub[0])
	{
		i = 0;
		if (sub[0] == '-')
			++i;
		if (sub[i] == '*')
			n = va_arg(args, int);
		else
			n = ft_atoi(&(sub[i]));
		if (sub[0] != '-')
			ft_printnchars(n - 1, ' ');
	}
	c = va_arg(args, int);
	write (1, &c, 1);
	if (sub[0] == '-')
		ft_printnchars(n - 1, ' ');
	return (n);
}

ssize_t		ft_putstr(const char *sub, va_list args)
{
	ssize_t n;
	size_t 	width;
	size_t 	acc;
	char		*s;

	n = 0;
	acc = -1;
	if (sub[0])
		width = ft_flagcheck(sub, args, &acc);
	s = va_arg(args, char*);
	if (acc > ft_strlen(s))
		acc = ft_strlen(s);
	if (sub[0] != '-')
		n += ft_printnchars(width - acc, ' ');
	n += write(1, s, acc);
	if (sub[0] == '-')
		n += ft_printnchars(width - acc, ' ');
	return (n);
}

ssize_t		ft_putint(const char *sub, va_list args)
{
	ssize_t n;
	size_t 	width;
	size_t 	acc;
	char 		*s;

	width = 0;
	acc = 0;
	if (sub[0])
		width = ft_flagcheck(sub, args, &acc);
	width = (!width && acc) ? acc : width;
	s = ft_itoa(va_arg(args, int));
	if (!sub[0])
		n = write(1, s, ft_strlen(s));
	else if (s[0] != '-')
		n = ft_printposnbr(sub, s, width, acc);
	else
		n = ft_printnegnbr(sub, s, width, acc);
	free(s);
	return (n);
}

