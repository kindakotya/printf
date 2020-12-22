/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 10:36:27 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/02 12:45:57 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ss;
	int		ss_len;

	if (!s1 || !s2)
		return (NULL);
	ss_len = ft_strlen(s1) + ft_strlen(s2);
	ss = (char *)malloc((ss_len + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	while (*s1 != '\0')
		*ss++ = *s1++;
	while (*s2 != '\0')
		*ss++ = *s2++;
	*ss++ = '\0';
	return (ss - ss_len - 1);
}
