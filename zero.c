/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 15:53:28 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 04:48:34 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			null_with_precis_c(t_precis *nb)
{
	int		i;
	char	x;

	i = nb->min;
	if (nb->zero == 1)
		x = '0';
	else
		x = ' ';
	while (i > 1)
	{
		ft_putchar(x);
		i--;
	}
	return (nb->min);
}

int			null_with_precis_s(t_precis *nb)
{
	int		i;
	char	x;

	i = nb->min;
	if (nb->zero == 1)
		x = '0';
	else
		x = ' ';
	while (i > 0)
	{
		ft_putchar(x);
		i--;
	}
	return (nb->min);
}

int			zero_with_less(t_precis *nb)
{
	int		i;

	i = nb->min;
	ft_putchar('0');
	i--;
	while (i-- > 0)
		ft_putchar(' ');
	return (nb->min);
}

int			zero_fill_char(t_precis *nb)
{
	int		i;

	i = nb->min;
	while (i > 1)
	{
		ft_putchar('0');
		i--;
	}
	return (nb->min - 1);
}

int			zero_fill(char *str, t_precis *nb)
{
	int		j;
	int		diff;

	j = 0;
	if (nb->min < (int)ft_strlen(str))
		nb->min = (int)ft_strlen(str);
	if (nb->min <= (int)ft_strlen(str) && (nb->moins == 1 || nb->plus == 1 ||
				nb->space == 1))
		nb->min++;
	diff = nb->min - ft_strlen(str);
	zero_fill1(nb, &diff);
	if (str[0] != '-')
	{
		while (diff > 0)
		{
			ft_putchar('0');
			diff--;
		}
		ft_putstr(str);
		return (nb->min);
	}
	diff = nb->min - ft_strlen(str);
	if (str[0] == '-')
		return (zero_fill2(nb, str, &diff, &j));
	return (nb->min);
}
