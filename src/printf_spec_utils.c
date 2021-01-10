/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:59:20 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/10 18:48:17 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

ssize_t		ft_printposnbr(const char *sub, const char *s,
	ssize_t width, ssize_t acc)
{
	ssize_t n;

	if (ft_strchr(sub, '.') && !acc)
		return (ft_printnchars(width, ' ', 0));
	n = 0;
	if (!ft_strchr(sub, '-') && acc > (ssize_t)ft_strlen(s))
		n += ft_printnchars(width - acc, ' ', &width);
	else if (((!acc && !ft_strchr(sub, '0')) ||
	(acc && acc < (ssize_t)ft_strlen(s))) && !ft_strchr(sub, '-'))
		n += ft_printnchars(width - ft_strlen(s), ' ', &width);
	if (ft_strchr(sub, '0') && width > (ssize_t)ft_strlen(s) && !acc)
		n += ft_printnchars(width - ft_strlen(s), '0', &width);
	else
		n += ft_printnchars(acc - ft_strlen(s), '0', &width);
	n += write(1, s, ft_strlen(s));
	width -= ft_strlen(s);
	if (ft_strchr(sub, '-'))
		n += ft_printnchars(width, ' ', 0);
	return (n);
}

ssize_t		ft_printnegnbr(const char *sub, const char *s,
	ssize_t width, ssize_t acc)
{
	int		ox;
	ssize_t n;

	n = 0;
	ox = 1;
	if (s[1] == 'x' || s[1] == 'X')
		ox = 2;
	if (!ft_strchr(sub, '-') && acc > (ssize_t)ft_strlen(s) - ox)
		n += ft_printnchars(width - acc - ox, ' ', &width);
	else if (((!acc && !ft_strchr(sub, '0')) ||
	(acc && acc < (ssize_t)ft_strlen(s) - ox)) && !ft_strchr(sub, '-'))
		n += ft_printnchars(width - ft_strlen(s), ' ', &width);
	n += write(1, s, ox);
	--width;
	if (ft_strchr(sub, '0') && !acc)
		n += ft_printnchars(width - ft_strlen(s) + ox, '0', &width);
	else
		n += ft_printnchars(acc - ft_strlen(s) + ox, '0', &width);
	n += write(1, s + ox, ft_strlen(s) - ox);
	width -= ft_strlen(s) - ox;
	if (ft_strchr(sub, '-'))
		n += ft_printnchars(width, ' ', 0);
	return (n);
}

char		*ft_bonusflags(const char *sub, char **s, char conv)
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
