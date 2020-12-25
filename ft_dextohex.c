/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dextohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:05:02 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/25 16:27:39 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_hexlen(long int n)
{
	size_t nrazr;

	nrazr = 1;
	if (n < 0)
	{
		n = -n;
		++nrazr;
	}
	while (n / 16)
	{
		++nrazr;
		n /= 16;
	}
	return (nrazr);
}

static char	ft_puthex(unsigned int n, char conv)
{
	if (n < 10 )
		return (n + '0');
	else if (conv == 'x')
		return (n - 10 + 'a');
	else
		return (n - 10 + 'A');
}

char	*ft_dextohex(long int n, char conv)
{
	size_t nrazr;
	char *hex;

	nrazr  = ft_hexlen(n);

	hex = malloc((nrazr + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	if (n < 0)
	{
		hex[0] = '-';
		n = -n;
	}
	hex[nrazr] = '\0';
	while (n)
	{
		--nrazr;
		hex[nrazr] = ft_puthex(n % 16, conv);
//		printf("\nhex[%zu] = %c\n", nrazr, hex[nrazr]);
		n /= 16;
	}
//	printf("\ndex = %s\n", hex);
	return (hex);
}