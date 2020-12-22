/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:14 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/22 23:06:41 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_stop(const char *s, size_t i)
{
	while (s[i] != '%' && s[i])
	{
		write(1, &(s[i++]), 1);
	}
	return (i);
}

static int		ft_isconv(int c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' &&
		c != 'i' && c != 'u' && c != 'x' && c != 'X' && c != '%')
			return (0);
	return (1);
}

static int		ft_symb(const char *s, size_t *i, va_list args)
{
	char *sub;
	ssize_t n;

	n = *i;
	while (!(ft_isconv(s[*i])) && s[*i])
		++(*i);
	if (s[*i] == '%')
		return (write(1, "%", 1));
	sub = ft_substr(s, n, *i - n);
	if (s[*i] == 'c')
		n = ft_putchar(sub, args);
	else if (s[*i] == 's')
		n = ft_putstr(sub, args);
	else if (s[*i] == 'd' || s[*i] == 'i')
		n = ft_putint(sub, args);
	// else if (s[i])
	free(sub);
	return (n);
}

int						ft_printf(const char *s, ...)
{
	size_t i;
	va_list args;
	char *str;
	int n;
	int diff;

	if (!s)
		return (0);
	str = ft_strdup(s);
	va_start(args, s);
	i = 0;
	diff = 0;
	n = 0;
	while (str[i])
	{
		i = ft_stop(str, i) + 1;
		n += i - diff;
		if (str[i])
			n += ft_symb(str, &i, args) + 1;
		++i;
		diff = i;
	}
	free(str);
	va_end(args);
	return (n);
}