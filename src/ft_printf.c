/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/10 20:48:26 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int		ft_stop(const char *s, size_t i, ssize_t *n)
{
	while (s[i] != '%' && s[i] && i < ft_strlen(s))
		*n += write(1, &(s[i++]), 1);
	return (i);
}

static t_struct	ft_screat(va_list args)
{
	t_struct s_args;


}

static ssize_t	ft_callconv(char *sub, va_list args, char conv)
{
	if (conv == 'c')
		return (ft_putchar(sub, args, conv));
	else if (conv == '%')
		return(ft_putchar(sub, args, conv));
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
	while (!(s[*i] != 'c' && s[*i] != 's' && s[*i] != 'p'
	&& s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'u'
	&& s[*i] != 'x' && s[*i] != 'X' && s[*i] != '%') && s[*i])
		++(*i);
	sub = ft_substr(s, start, *i - start);
	n = ft_callconv(sub, args, s[*i]);
	free(sub);
	return (n);
}

int				ft_printf(const char *s, ...)
{
	size_t	i;
	ssize_t	n;
	va_list	args;

	if (!s)
		return (0);
	va_start(args, s);
	i = 0;
	n = 0;
	while (s[i] && i <= ft_strlen(s))
	{
		i = ft_stop(s, i, &n) + 1;
		if (s[i] && i <= ft_strlen(s))
			n += ft_symb(s, &i, args);
		++i;
	}
	va_end(args);
	return (n);
}
