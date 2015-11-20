/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 04:22:24 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 04:22:26 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		zero_fill2(t_precis *nb, char *str, int *diff, int *j)
{
	ft_putchar('-');
	while (*diff > 0)
	{
		ft_putchar('0');
		(*diff)--;
	}
	while (str[*j])
	{
		if (ft_isdigit(str[*j]) == 1)
			ft_putchar(str[*j]);
		(*j)++;
	}
	return (nb->min);
}

void	zero_fill1(t_precis *nb, int *diff)
{
	if (nb->plus == 1)
	{
		ft_putchar('+');
		(*diff)--;
	}
	else if (nb->space == 1)
	{
		ft_putchar(' ');
		(*diff)--;
	}
}
