/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/06 18:05:59 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		ft_stop(const char *s, size_t i, ssize_t *n)
{
	while (s[i] != '%' && s[i])
		*n += write(1, &(s[i++]), 1);
	return (i);
}

static int		ft_isconv(int c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' &&
		c != 'i' && c != 'u' && c != 'x' && c != 'X' && c != '%')
		return (0);
	return (1);
}

static ssize_t	ft_callconv(char *sub, va_list args, char conv)
{
	if (conv == 'c')
		return (ft_putchar(sub, args));
	else if (conv == 's')
		return (ft_putstr(sub, args));
	else if (conv == 'd' || conv == 'i')
		return (ft_putint(sub, args, conv));
	else if (conv == 'x' || conv == 'X')
		return (ft_putint(sub, args, conv));
	else if (conv == 'p')
		return (ft_putpoint(sub, args));
	else if (conv == 'u')
		return (ft_putuint(sub, args));
	return (0);
}

static ssize_t	ft_symb(const char *s, size_t *i, va_list args)
{
	char	*sub;
	size_t	start;
	ssize_t	n;

	start = *i;
	while (!(ft_isconv(s[*i])) && s[*i])
		++(*i);
	if (s[*i] == '%')
		return (write(1, "%", 1));
	sub = ft_substr(s, start, *i - start);
	n = ft_callconv(sub, args, s[*i]);
	free(sub);
	return (n);
}

int				ft_printf(const char *s, ...)
{
	char	*str;
	size_t	i;
	ssize_t	n;
	va_list	args;

	if (!s)
		return (0);
	str = ft_strdup(s);
	va_start(args, s);
	i = 0;
	n = 0;
	while (str[i])
	{
		i = ft_stop(str, i, &n) + 1;
		if (str[i])
			n += ft_symb(str, &i, args);
		++i;
	}
	free(str);
	va_end(args);
	return (n);
}
