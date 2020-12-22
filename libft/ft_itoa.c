/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:15:37 by gmayweat          #+#    #+#             */
/*   Updated: 2020/11/28 13:59:32 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int i;

	i = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return ((i == 0) ? 1 : i);
}

static char	*ft_intmin(void)
{
	char	*str;
	char	*podstr;
	int		i;

	str = malloc(12 * sizeof(char));
	if (str == NULL)
		return (NULL);
	podstr = "-2147483648\0";
	i = 0;
	while (podstr[i])
	{
		str[i] = podstr[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		num;
	char	*str;

	if (n == -2147483648)
		return (ft_intmin());
	num = ft_intlen(n);
	str = malloc((num + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = (n < 0) ? '-' : str[0];
	str[0] = (n == 0) ? '0' : str[0];
	n = (n < 0) ? -n : n;
	str[num] = '\0';
	while (n)
	{
		str[--num] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
