/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:59:20 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/08 21:18:11 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

ssize_t		ft_printposnbr(const char *sub, const char *s,
	ssize_t width, ssize_t acc)
{
	ssize_t n;

	n = 0;
	// if (!acc || acc < (ssize_t)ft_strlen(s))
	// 	acc = ft_strlen(s);
	if (sub[0] != '-' && (sub[0] != '0' || (acc && sub[0] == '0')))
		n += ft_printnchars(width - acc, ' ');
	if (sub[0] == '0' && width - acc - ft_strlen(s) > 0)
		n += ft_printnchars(width - acc, '0');
	else
		n += ft_printnchars(acc - ft_strlen(s), '0');
	n += write(1, s, ft_strlen(s));
	if (sub[0] == '-')
		n += ft_printnchars(width - acc, ' ');
	return (n);
}

ssize_t		ft_printnegnbr(const char *sub, const char *s,
	ssize_t width, ssize_t acc)
{
	ssize_t n;

	n = 0;
	if (sub[0] != '-' && sub[0] != '0' && acc)
		n += ft_printnchars(width - acc - 1, ' ');
	else if (sub[0] != '-' && sub[0] != '0' && !acc)
		n += ft_printnchars(width - ft_strlen(s), ' ');
	n += write(1, "-", 1);
	if (sub[0] == '0' && !acc)
		n += ft_printnchars(width - ft_strlen(s), '0');
	else
		n += ft_printnchars(acc - ft_strlen(s) + 1, '0');
	n += write(1, s + 1, ft_strlen(s) - 1);
	if (sub[0] == '-' && acc)
		n += ft_printnchars(width - acc - 1, ' ');
	else if (sub[0] == '-' && !acc)
		n += ft_printnchars(width - ft_strlen(s), ' ');
	return (n);
}

char	*ft_bonusflags(const char *sub, char **s, char conv)
{
	int		i;
	int		j;
	char	*meow;

	i = 1;
	j = 0;
	if (ft_strchr(sub, '+'))
		meow = ft_strjoin("+", *s);
	else if (ft_strchr(sub, ' '))
		meow = ft_strjoin(" ", *s);
	else if (ft_strchr(sub, '#') && conv == 'x')
		meow = ft_strjoin("0x", *s);
	else if (ft_strchr(sub, '#') && conv == 'X')
		meow = ft_strjoin("0X", *s);
	else
		meow = "\0";
	free(*s);
	return (meow);
}