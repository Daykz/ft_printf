/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 22:34:22 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:15:47 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			zero_for_p(t_precis *nb)
{
	int		n;

	n = nb->min - 2;
	while (n > 1)
	{
		ft_putchar('0');
		n--;
	}
	return (nb->min - 3);
}

int			uchar_limit(int n)
{
	int		max;
	int		diff;

	max = 255;
	if (n < 0)
	{
		n += max + 1;
	}
	if (n > max)
	{
		diff = n - max - 1;
		n = diff;
		if (n > max)
			return (uchar_limit(n));
		return (n);
	}
	else
		return (n);
}

int			char_limit(int n)
{
	int		max;
	int		min;
	int		diff;

	max = 127;
	min = -128;
	if (n > max)
	{
		diff = n - max - 1;
		n = min + diff;
		if (n > max)
			return (char_limit(n));
		return (n);
	}
	else if (n < min)
	{
		diff = n - min;
		n = max + diff + 1;
		if (n < min)
			return (char_limit(n));
		return (n);
	}
	else
		return (n);
}
