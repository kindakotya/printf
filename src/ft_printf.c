/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/12 18:17:39 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static void		ft_fillbox(const char *s, size_t start, size_t len, t_prarg *s_box)
{
	char sub[len + 1];
	size_t i;

	i = 0;
	sub[len] = '\0';
	while (i < len)
		sub[i++] = s[start++];
	if (ft_strchr(sub, '-'))
		s_box->minus = 1;
	else if (ft_strchr(sub, '0'))
		s_box->zero = 1;
	if (ft_strchr(sub, '+'))
		s_box->bonf = '+';
	else if (ft_strchr(sub, ' '))
		s_box->bonf = ' ';
	else if (ft_strchr(sub, '#'))
		s_box->bonf = '#';
	ft_flagcheck(sub, s_box);
	if (s_box->width < 0)
	{
		s_box->minus = 1;
		s_box->width *= -1;
	}
	if (s_box->zero && s_box->minus)
		s_box->zero = 0;
}

static void	ft_sclean(t_prarg *s_box)
{
	s_box->is_acc = 0;
	s_box->width = 0;
	s_box->acc = 0;
	s_box->minus = 0;
	s_box->zero = 0;
	s_box->bonf = 0;
}

static ssize_t	ft_callconv(t_prarg *s_box)
{
	if (s_box->conv == 'c')
		return (ft_putchar(s_box));
	else if (s_box->conv == '%')
		return(ft_putchar(s_box));
	else if (s_box->conv == 's')
		return (ft_putstr(s_box));
	else if (s_box->conv == 'd' || s_box->conv == 'i')
		return (ft_putint(s_box));
	else if (s_box->conv == 'x' || s_box->conv == 'X')
		return (ft_putint(s_box));
	else if (s_box->conv == 'p')
		return (ft_putpoint(s_box));
	else if (s_box->conv == 'u')
		return (ft_putuint(s_box));
	return (0);
}

static ssize_t	ft_symb(const char *s, size_t *i, t_prarg *s_box)
{
	size_t	start;
	ssize_t	n;

	start = *i;
	while (s[*i] != 'c' && s[*i] != 's' && s[*i] != 'p'
	&& s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'u'
	&& s[*i] != 'x' && s[*i] != 'X' && s[*i] != '%' && s[*i])
		++(*i);
	ft_fillbox(s, start, *i - start, s_box);
	s_box->conv = s[*i];
	n = ft_callconv(s_box);
	return (n);
}

int				ft_printf(const char *s, ...)
{
	size_t	i;
	ssize_t	n;
	t_prarg s_box;

	if (!s)
		return (0);
	va_start(s_box.args, s);
	i = 0;
	n = 0;
	while (s[i] && i <= ft_strlen(s))
	{
		ft_sclean(&s_box);
		while (s[i] != '%' && s[i] && i < ft_strlen(s))
			n += write(1, &(s[i++]), 1);
		++i;
		if (s[i] && i <= ft_strlen(s))
			n += ft_symb(s, &i, &s_box);
		++i;
	}
	va_end(s_box.args);
	return (n);
}
