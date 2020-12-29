/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:50:17 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/29 14:42:42 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*mem;

	i = 0;
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	while (i < nmemb * size)
		((unsigned char *)mem)[i++] = '\0';
	return (mem);
}
