/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:27 by gmayweat          #+#    #+#             */
/*   Updated: 2020/12/24 01:47:35 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main()
{
	int i;

	//char *s = "meow";
	i = 10;
	// char ch = 'A';
//	ft_printf("%*ca\n", 10, 'A');

int num = -4;

	ft_printf("1____________\n");
	ft_printf("my = %dc\n", -2147483648);
	//printf("pr = %dc\n", -2147483648);

	printf("2_____%%5d_____\n\n");
	ft_printf("my = %5dc\n", num);
	printf("pr = %5dc\n\n", num);

	printf("3_____%%5.3d______\n\n");
	ft_printf("my = %5.3dc\n", num);
	printf("pr = %5.3dc\n\n", num);

	printf("4_____%%-5d______\n\n");
	ft_printf("my = %-5dc\n", num);
	printf("pr = %-5dc\n\n", num);

	printf("5_____%%-5.3d______\n\n");
	ft_printf("my = %-5.3dc\n", num);
	printf("pr = %-5.3dc\n\n", num);

	printf("6_____%%05d______\n\n");
	ft_printf("my = %05dc\n", num);
	printf("pr = %05dc\n\n", num);

	printf("7_____%%0.d______\n\n");
	ft_printf("my = %0.dc\n", num);
	printf("pr = %0.dc\n\n", num);

	printf("8_____%%5.d______\n\n");
	ft_printf("my = %5.dc\n", num);
	printf("pr = %5.dc\n\n", num);

	printf("9_____%%.4d______\n\n");
	ft_printf("my = %.4dc\n", num);
	printf("pr = %.4dc\n\n", num);
	// i = 0;
	// while (str[i])
	// 	++i;
	// write(1, str, i);

	// write(1, &ch, 1);
	// write(1, "\n%\n", 3);
	return (0);
}
