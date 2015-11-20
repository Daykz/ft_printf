/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizehmtoa.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 00:49:51 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:26:37 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		hexavalue(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	else if (10 <= x && x <= 15)
	{
		x = x - 10;
		return (65 + x);
	}
	return (0);
}

char			*ft_sizehmtoa(size_t n)
{
	char		*p;
	int			size;
	size_t		x;

	x = n;
	size = 0;
	while (x > 16)
	{
		x = x / 16;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 16;
			p[size] = hexavalue(x);
			n = n / 16;
			size--;
		}
	}
	return (p);
}
