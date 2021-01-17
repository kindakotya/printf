/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmayweat <gmayweat@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:43:54 by gmayweat          #+#    #+#             */
/*   Updated: 2021/01/17 18:52:23 by gmayweat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_struct
{
	ssize_t width;
	int		is_acc;
	ssize_t acc;
	int		minus;
	int		zero;
	char	conv;
	va_list args;
	char	bonf;
}				t_prarg;

int				ft_printf(const char *s, ...);
ssize_t			ft_putchar(t_prarg *s_box);
ssize_t			ft_putstr(t_prarg *s_box);
ssize_t			ft_putint(t_prarg *s_box);
ssize_t			ft_putuint(t_prarg *s_box);
ssize_t			ft_putpoint(t_prarg *s_box);
ssize_t			ft_printnch(size_t n, char c, ssize_t *width);
void			ft_flagcheck(const char *sub, t_prarg *s_box);
ssize_t			ft_printposnbr(const char *s, t_prarg *s_box);
ssize_t			ft_printnegnbr(const char *s, t_prarg *s_box);
char			*ft_bonusflags(char **s, t_prarg *s_box);
char			*ft_dextohex(unsigned long int n, char conv);

#endif
