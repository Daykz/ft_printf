/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 01:30:23 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:05:06 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_precision(char *str, t_precis *nb, int n)
{
	if (nb->zero == 1 && nb->pt == 0 && nb->moins == 0)
		return (zero_fill(str, nb));
	if (nb->plus == 1 && n >= 0)
	{
		ft_putchar('+');
		return (1);
	}
	if (nb->space == 1 && nb->plus == 0 && n >= 0 && nb->moins == 0 &&
			nb->zero == 0)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}
