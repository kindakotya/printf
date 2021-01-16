/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:30:14 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/16 23:54:04 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

ssize_t		ft_putchar(t_prarg *s_box)
{
	char		c;

	if (!s_box->width)
		s_box->width = 1;
	if (s_box->conv == 'c')
		c = va_arg(s_box->args, int);
	else
		c = '%';
	if (c == '%' && s_box->zero)
		ft_printnch(s_box->width - 1, '0', &s_box->width);
	if (!s_box->minus)
		ft_printnch(s_box->width - 1, ' ', &s_box->width);
	write(1, &c, 1);
	if (s_box->minus)
		ft_printnch(s_box->width - 1, ' ', 0);
	return (s_box->width);
}

ssize_t		ft_putstr(t_prarg *s_box)
{
	ssize_t		n;
	char		*s;

	n = 0;
	s = va_arg(s_box->args, char*);
	if (!s)
		s = "(null)\0";
	else if (!s || !s[0])
		s = "\0";
	if (!s_box->is_acc || s_box->acc > (ssize_t)ft_strlen(s))
		s_box->acc = ft_strlen(s);
	if (!s_box->minus)
		n += ft_printnch(s_box->width - s_box->acc, ' ', &s_box->width);
	n += write(1, s, s_box->acc);
	if (s_box->minus)
		n += ft_printnch(s_box->width - s_box->acc, ' ', 0);
	return (n);
}

ssize_t		ft_putint(t_prarg *s_box)
{
	ssize_t	n;
	char	*s;

	s = ft_itoa(va_arg(s_box->args, int));
	if (s_box->bonf)
		s = ft_bonusflags(&s, s_box);
	if (s_box->bonf || s[0] == '-')
		n = ft_printnegnbr(s, s_box);
	else
		n = ft_printposnbr(s, s_box);
	free(s);
	return (n);
}

ssize_t		ft_putuint(t_prarg *s_box)
{
	ssize_t			n;
	char			*s;

	if (s_box->conv == 'u')
		s = ft_itoa(va_arg(s_box->args, unsigned int));
	else
		s = ft_dextohex(va_arg(s_box->args, unsigned int), s_box->conv);
	if (s_box->bonf)
		s = ft_bonusflags(&s, s_box);
	if (s_box->bonf)
		n = ft_printnegnbr(s, s_box);
	else
		n = ft_printposnbr(s, s_box);
	free(s);
	return (n);
}

ssize_t		ft_putpoint(t_prarg *s_box)
{
	char	*s;
	ssize_t n;

	n = 0;
	s = ft_dextohex(va_arg(s_box->args, unsigned long int), 'x');
	if (s[0] == 0)
		return (write(1, "0x0", 3));
	if (!s_box->minus)
		n += ft_printnch(s_box->width - ft_strlen(s) - 2, ' ', 0);
	n += write(1, "0x", 2);
	n += write(1, s, ft_strlen(s));
	if (s_box->minus)
		n += ft_printnch(s_box->width - ft_strlen(s) - 2, ' ', 0);
	free(s);
	return (n);
}
