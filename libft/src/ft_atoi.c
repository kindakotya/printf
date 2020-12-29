/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:13:44 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/25 10:17:04 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					i;
	int					spp;
	unsigned long long	num;

	spp = 0;
	while (str[spp] == '\f' || str[spp] == '\n' || str[spp] == ' '
		|| str[spp] == '\r' || str[spp] == '\t' || str[spp] == '\v')
		++spp;
	num = 0;
	if (str[spp] == '-' || str[spp] == '+')
		i = spp + 1;
	else
		i = spp;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (num > 9223372036854775807 && str[spp] == '-')
		return (0);
	if (num > 9223372036854775807)
		return (-1);
	if (str[spp] == '-')
		return ((int)(-num));
	return ((int)num);
}
