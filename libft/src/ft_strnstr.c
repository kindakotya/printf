/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 23:05:39 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/29 14:42:42 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[0])
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] &&
				big[i + j] && little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
