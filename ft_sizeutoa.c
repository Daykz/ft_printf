/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeutoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 19:40:28 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:25:47 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_sizeutoa(size_t n)
{
	char		*p;
	int			size;
	size_t		x;

	x = n;
	size = 0;
	while (x > 10)
	{
		x /= 10;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			p[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (p);
}
