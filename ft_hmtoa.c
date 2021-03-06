/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmtoa.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 00:45:49 by dmathe            #+#    #+#             */
/*   Updated: 2015/02/06 01:04:02 by dmathe           ###   ########.fr       */
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

char			*ft_hmtoa(unsigned int n)
{
	char			*p;
	int				size;
	unsigned int	x;

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
