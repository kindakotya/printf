/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:39:29 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/30 11:13:45 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

ssize_t		ft_printnchars(size_t n, char c)
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

size_t		ft_flagcheck(const char *sub, va_list args, size_t *acc)
{
	int		i;
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
	if (!width && acc && *acc)
		return (*acc);
	return (width);
}

ssize_t		ft_printposnbr(const char *sub, const char *s, size_t width, size_t acc)
{
	ssize_t n;

	n = 0;
	if (!acc)
		acc = ft_strlen(s);
	if (sub[0] != '-' && sub[0] != '0')
		n += ft_printnchars(width - acc, ' ');
	if (sub[0] == '0' && acc == ft_strlen(s))
		n += ft_printnchars(width - acc, '0');
	else
		n += ft_printnchars(acc - ft_strlen(s), '0');
	n += write(1, s, ft_strlen(s));
	if (sub[0] == '-')
		n += ft_printnchars(width - acc, ' ');
	return (n);
}

ssize_t		ft_printnegnbr(const char *sub, const char *s, size_t width, size_t acc)
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

char	*ft_addplus(char **s)
{
	int i;
	char *meow;
	int j;

	i = 1;
	j = 0;
	meow = malloc((ft_strlen(*s) + 2) * sizeof(char));
	if (!meow)
		return (NULL);
	meow[0] = '+';
	while ((*s)[j])
		meow[i++] = (*s)[j++];
	meow[i] = '\0';
	free(*s);
	return (meow);
}