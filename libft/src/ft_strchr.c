/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:30:47 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/29 14:42:42 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (c == '\0')
		return ((char*)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)(s + i));
		++i;
	}
	return (NULL);
}
