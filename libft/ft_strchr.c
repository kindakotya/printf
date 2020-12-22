/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:30:47 by gmayweat          #+#    #+#             */
/*   Updated: 2020/11/24 18:14:29 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		while (s[i])
			++i;
		return (&(((char*)s)[i]));
	}
	while (s[i])
	{
		if (s[i] == c)
			return (&(((char*)s)[i]));
		++i;
	}
	return (NULL);
}
