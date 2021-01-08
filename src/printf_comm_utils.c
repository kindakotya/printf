/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_comm_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:39:29 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/08 20:59:02 by gmayweat         ###   ########.fr       */
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

ssize_t		ft_flagcheck(const char *sub, va_list args, ssize_t *acc)
{
	size_t	i;
	ssize_t	width;

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

char		*ft_addchar(char **s, char c)
{
	int		i;
	int		j;
	char	*meow;

	i = 1;
	j = 0;
	meow = malloc((ft_strlen(*s) + 2) * sizeof(char));
	if (!meow)
		return (NULL);
	meow[0] = c;
	while ((*s)[j])
		meow[i++] = (*s)[j++];
	meow[i] = '\0';
	free(*s);
	return (meow);
}

