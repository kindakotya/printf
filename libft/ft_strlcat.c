/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:29:31 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/02 12:46:07 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	j = len_dst;
	if (len_dst < size - 1 && size > 0)
	{
		while (src[i] && len_dst + i < size - 1)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = '\0';
	}
	if (len_dst >= size)
		len_dst = size;
	return (len_dst + len_src);
}
