/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 23:58:28 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:06:05 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		intprecis2(t_precis *nb, int *j, int *len, char *str)
{
	if (nb->min > nb->max)
	{
		if (ft_atoi(str) < 0)
			(*j)++;
		while ((*j) < nb->min)
		{
			ft_putchar(' ');
			(*j)++;
			(*len)++;
		}
	}
}

int			size_fields_nul(t_precis *nb)
{
	int		i;

	i = nb->min;
	while (i > 1)
	{
		ft_putchar(' ');
		i--;
	}
	return (nb->min);
}

int			size_fields_pointer(size_t n, t_precis *nb)
{
	int		i;
	int		diff;

	i = 0;
	diff = 0;
	diff = nb->min - n;
	if (nb->min < (int)n)
		return (0);
	while (i < diff)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int			size_fields_char(t_precis *nb)
{
	int		i;

	i = nb->min;
	while (i > 1)
	{
		ft_putchar(' ');
		i--;
	}
	return (nb->min - 1);
}

int			size_fields_str(char *str, t_precis *nb)
{
	int		i;
	int		diff;

	diff = 0;
	i = nb->min;
	if (nb->min <= (int)ft_strlen(str))
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
	else
	{
		diff = i - ft_strlen(str);
		while (diff != 0)
		{
			ft_putchar(' ');
			diff--;
		}
		ft_putstr(str);
		return (nb->min);
	}
}
