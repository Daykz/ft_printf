/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 18:55:23 by dmathe            #+#    #+#             */
/*   Updated: 2015/02/04 18:57:42 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_motoa(uintmax_t n)
{
	char			*p;
	int				size;
	uintmax_t		x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x = x / 8;
		size++;
	}
	p = (char *)malloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			p[size] = 48 + x;
			n = n / 8;
			size--;
		}
	}
	return (p);
}
