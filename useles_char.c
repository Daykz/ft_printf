/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useles_lett.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 03:00:15 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 04:59:41 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			max_wchar(t_precis *nb, int len)
{
	if (nb->pt == 0)
		return (1);
	if (len <= 7)
		nb->lim += 1;
	else if (len > 7 && len <= 11)
		nb->lim += 2;
	else if (len > 11 && len <= 16)
		nb->lim += 3;
	else if (len > 16)
		nb->lim += 4;
	if (nb->lim <= nb->max)
		return (1);
	else
		return (0);
}

int			precis_for_wchar(int *len, t_precis *nb, char *str)
{
	int		n;
	char	c;

	n = *len;
	if (nb->zero == 1)
		c = '0';
	else
		c = ' ';
	if (nb->moins == 1)
		ft_putstr(str);
	while (n < nb->min)
	{
		ft_putchar(c);
		n++;
	}
	if (nb->moins == 0)
		ft_putstr(str);
	return ((nb->min > *len) ? (nb->min - *len) : 0);
}

int			useles_char(t_precis *nb, char c)
{
	if (nb->precis != 0 && nb->moins == 0)
		precis_for_char(nb);
	ft_putchar(c);
	if (nb->precis != 0 && nb->moins == 1)
		precis_for_char(nb);
	return (nb->min);
}

int			precis_for_char(t_precis *nb)
{
	int		n;
	char	c;

	n = nb->min;
	if (nb->zero == 1)
		c = '0';
	else
		c = ' ';
	while (n > 1)
	{
		ft_putchar(c);
		n--;
	}
	return (nb->min);
}
