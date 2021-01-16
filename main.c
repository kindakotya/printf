/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:27 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/17 00:01:10 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int main()
{
	int		a = 4;
	int		b = 2;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	int T = 70;
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";
	   printf("%0*.*i,%0*.*d,%0*.*d,%0*.*d,%0*.*d, %0*.*d, %0*.*d, %0*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	ft_printf("%0*.*i,%0*.*d,%0*.*d,%0*.*d,%0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
	// char *s;
	// s = malloc(4);
	// int num = -4;
	// ft_printf("1____________\n\n");
	// ft_printf("my = %+dc\n", 214748368);
	// printf("pr = %+-dc\n\n", 214748368);

	// printf("2_____%%5d_____\n\n");
	// ft_printf("my = %5dc\n", num);
	// printf("pr = %5dc\n\n", num);

	// printf("3_____%%5.3d______\n\n");
	// ft_printf("my = %5.3dc\n", num);
	// printf("pr = %5.3dc\n\n", num);

	// printf("4_____%%-5d______\n\n");
	// printf("x = %d\n", ft_printf("my = %-5dc\n", num));
	// printf("p = %d\n\n", printf("pr = %-5dc\n", num));

	// printf("5_____%%-5.3d______\n\n");
	// printf("x = %d\n", ft_printf("my = %-5.3dc\n", num));
	// printf("p = %d\n\n", printf("pr = %-5.3dc\n", num));

	// printf("6_____%%05d______\n\n");
	// ft_printf("my = %05dc\n", num);
	// printf("pr = %05dc\n\n", num);

	// printf("7_____%%0.d______\n\n");
	// ft_printf("my = %.dc\n", num);
	// printf("pr = %.dc\n\n", num);

	// printf("8_____%%5.d______\n\n");
	// ft_printf("my = %5.dc\n", num);
	// printf("pr = %5.dc\n\n", num);

	// printf("9_____%%.4d______\n\n");
	// ft_printf("my = %.4dc\n", num);
	// printf("pr = %.4dc\n\n", num);

	// printf("10_____%%X______\n\n");
	// ft_printf("my = %Xc\n", 87346786);
	// printf("pr = %Xc\n\n", 87346786);

	// printf("11_____%%x______\n\n");
	// ft_printf("my = %xc\n", 87346786);
	// printf("pr = %xc\n\n", 87346786);

	// printf("12_____%%p______\n\n");
	// ft_printf("my = %-130pc\n", s);
	// printf("pr = %-130pc\n\n", s);

	// ft_printf("13_____%%u_______\n\n");
	// ft_printf("my = %uc\n", 214748364);
	// printf("pr = %uc\n\n", 214748364);
	// ft_printf("13_____%%}}}s_______\n\n");
	// ft_printf("my = %dc\n", 'a');
	// printf("pr = %dc\n\n", 'a');
	// free(s);
	// ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	//ft_printf("%%*i 42 == |%*i|", 3, 42);
//	printf("%0-10x", 5);
	return (0);
}
