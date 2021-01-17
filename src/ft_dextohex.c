/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dextohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:05:02 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/17 17:36:10 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static size_t	ft_hexlen(unsigned long int n)
{
	size_t nrazr;

	nrazr = 1;
	while (n / 16)
	{
		++nrazr;
		n /= 16;
	}
	return (nrazr);
}

static char		ft_puthex(unsigned long int n, char conv)
{
	if (n < 10)
		return (n + '0');
	else if (conv == 'x')
		return (n - 10 + 'a');
	else
		return (n - 10 + 'A');
}

char			*ft_dextohex(unsigned long int n, char conv)
{
	size_t	nrazr;
	char	*hex;

	nrazr = ft_hexlen(n);
	hex = malloc((nrazr + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	hex[0] = '0';
	hex[nrazr] = '\0';
	while (n)
	{
		--nrazr;
		hex[nrazr] = ft_puthex(n % 16, conv);
		n /= 16;
	}
	return (hex);
}
