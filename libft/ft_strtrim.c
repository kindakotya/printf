/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:05:19 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/25 10:48:43 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_srav(char c, const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		if (s[i] == c)
			return (1);
		else
			++i;
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	char	*s0;
	size_t	i;
	size_t	j;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!ft_strlen(set))
		return (ft_strdup(s1));
	j = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	while (ft_srav(s1[i], set) && s1[i])
		++i;
	if (i == ft_strlen(s1) || !ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	while (ft_srav(s1[end], set) && end)
		--end;
	s0 = malloc((end - i + 2) * sizeof(char));
	if (s0 == NULL)
		return (NULL);
	while (i <= end)
		s0[j++] = s1[i++];
	s0[j] = '\0';
	return (s0);
}
