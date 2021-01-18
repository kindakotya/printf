/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:15:37 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/18 13:52:18 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int n)
{
	int i;

	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	else
		i = 0;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	if (!i)
		return (1);
	return (i);
}

char		*ft_itoa(long int n)
{
	int		num;
	char	*str;

	num = ft_numlen(n);
	str = malloc((num + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (!n)
		str[0] = '0';
	str[num] = '\0';
	while (n)
	{
		str[--num] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
