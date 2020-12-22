/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:39:29 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/22 23:56:22 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_printnchars(size_t n, char c)
{
	ssize_t i;

	i = 0;
	while (i < (ssize_t)n)
	{
		write(1, &c, 1);
		++i;
	}
	return (i);
}

size_t	ft_flagcheck(const char *sub, va_list args, size_t *acc)
{
	int			i;
	size_t	width;

	i = 0;
	if (sub[0] == '-' || sub[0] == '0')
		++i;
	if (ft_strchr(sub, '*') &&
	(!(ft_strchr(sub, '.')) || ft_strchr(sub, '*') < ft_strchr(sub, '.')))
		width = va_arg(args, size_t);
	else
		width = ft_atoi(&(sub[i]));
	if (ft_strchr(sub, '.') && *(ft_strchr(sub, '.') + 1) == '*')
		*acc = va_arg(args, size_t);
	else if (ft_strchr(sub, '.'))
		*acc = ft_atoi(ft_strchr(sub, '.') + 1);
	return (width);
}

ssize_t	ft_printnbr(const char *sub, const char *s, size_t width, size_t acc)
{
	ssize_t n;
	size_t len;

	n = 0;
	len = ft_strlen(s);
	acc = (acc) ? acc : len;
	len = (s[0] == '-') ? len - 1 : len;
	if (sub[0] != '-' && sub[0] != '0')
		n += ft_printnchars(width - acc, ' ');
	if (s[0] == '-')
		n += write(1, "-", 1);
	if (sub[0] == '0' && acc == ft_strlen(s))
		n += ft_printnchars(width - acc, '0');
	else
		n += ft_printnchars(acc - ft_strlen(s), '0');
	n += write(1, ++s, len);
	if (sub[0] == '-')
		n += ft_printnchars(width - acc, ' ');
	return (n);
}