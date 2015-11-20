/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:05:11 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:24:18 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_nb_digit(size_t n)
{
	unsigned int	result;

	result = 0;
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static void			ft_num_to_char(char *str, size_t n, size_t len, size_t neg)
{
	while (len != 0)
	{
		str[len - 1 + neg] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char				*ft_sizetoa(size_t n)
{
	char			*str;
	size_t			neg;
	size_t			len;

	len = ft_nb_digit(n);
	neg = 0;
	str = ft_strnew(len + neg + 1);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	str[len + neg] = '\0';
	ft_num_to_char(str, n, len, neg);
	return (str);
}
