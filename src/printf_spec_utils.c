/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:59:20 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/11 13:57:24 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

ssize_t		ft_printposnbr(const char *s, t_prarg *s_box)
{
	ssize_t n;

	if (s_box->is_acc && !s_box->acc)
		return (ft_printnch(s_box->width, ' ', 0));
	if (!s_box->is_acc || (s_box->acc && s_box->acc < (ssize_t)ft_strlen(s)))
		s_box->acc = ft_strlen(s);
	n = 0;
	if (!s_box->minus && (s_box->is_acc || !s_box->zero))
		n += ft_printnch(s_box->width - s_box->acc, ' ', &s_box->width);
	if (!s_box->is_acc && s_box->zero)
		n += ft_printnch(s_box->width - s_box->acc, '0', &s_box->width);
	else
		n += ft_printnch(s_box->acc - ft_strlen(s), '0', &s_box->width);
	n += write(1, s, ft_strlen(s));
	s_box->width -= ft_strlen(s);
	if (s_box->minus)
		n += ft_printnch(s_box->width, ' ', 0);
	return (n);
}

ssize_t		ft_printnegnbr(const char *s, t_prarg *s_box)
{
	int		ox;
	ssize_t n;

	n = 0;
	ox = 1;
	if (s[1] == 'x' || s[1] == 'X')
		ox = 2;
	if (!s_box->minus && s_box->acc > (ssize_t)ft_strlen(s) - ox)
		n += ft_printnch(s_box->width - s_box->acc - ox, ' ', &s_box->width);
	else if (((!s_box->is_acc && !s_box->zero) ||(s_box->is_acc
	&& s_box->acc < (ssize_t)ft_strlen(s) - ox)) && !s_box->minus)
		n += ft_printnch(s_box->width - ft_strlen(s), ' ', &s_box->width);
	n += write(1, s, ox);
	--s_box->width;
	if (s_box->zero && !s_box->is_acc)
		n += ft_printnch(s_box->width - ft_strlen(s) + ox, '0', &s_box->width);
	else
		n += ft_printnch(s_box->acc - ft_strlen(s) + ox, '0', &s_box->width);
	n += write(1, s + ox, ft_strlen(s) - ox);
	s_box->width -= ft_strlen(s) - ox;
	if (s_box->minus)
		n += ft_printnch(s_box->width, ' ', 0);
	return (n);
}

char		*ft_bonusflags(char **s, t_prarg *s_box)
{
	char	*meow;

	if (s_box->bonf == '+')
		meow = ft_strjoin("+", *s);
	else if (s_box->bonf == ' ')
		meow = ft_strjoin(" ", *s);
	else if (s_box->bonf == '#' && s_box->conv == 'x')
		meow = ft_strjoin("0x", *s);
	else if (s_box->bonf == '#' && s_box->conv == 'X')
		meow = ft_strjoin("0X", *s);
	else
		meow = "\0";
	free(*s);
	return (meow);
}
