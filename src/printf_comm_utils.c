/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_comm_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:39:29 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/11 14:12:00 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

ssize_t		ft_printnch(size_t n, char c, ssize_t *width)
{
	ssize_t i;

	i = 0;
	while (i < (ssize_t)n)
	{
		if (width)
			*width -= write(1, &c, 1);
		else
			write(1, &c, 1);
		++i;
	}
	return (i);
}

void		ft_flagcheck(const char *sub, t_prarg *s_box)
{
	size_t i;

	i = 0;
	if (ft_strchr(sub, '*') &&
	(!(ft_strchr(sub, '.')) || ft_strchr(sub, '*') < ft_strchr(sub, '.')))
	{
		s_box->is_width = 1;
		s_box->width = va_arg(s_box->args, size_t);
	}
	if (ft_strchr(sub, '.'))
	{
		s_box->is_acc = 1;
		if (*(ft_strchr(sub, '.') + 1) == '*')
			s_box->acc = va_arg(s_box->args, size_t);
		else
			s_box->acc = ft_atoi(ft_strchr(sub, '.') + 1);
	}
	while (!ft_isdigit(sub[i - 1]) && sub[i])
		if (ft_isdigit(sub[i++]))
		{
			s_box->width = ft_atoi(&(sub[i - 1]));
			s_box->is_width = 1;
		}
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