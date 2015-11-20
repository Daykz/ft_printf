/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 20:03:28 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:48:32 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_nb_digit(intmax_t n)
{
	unsigned int	result;

	result = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static void			ft_num_to_char(char *s, intmax_t n, size_t l, size_t neg)
{
	while (l != 0)
	{
		s[l - 1 + neg] = (n % 10) + '0';
		n /= 10;
		l--;
	}
}

char				*ft_mtoa(intmax_t n)
{
	char			*str;
	size_t			neg;
	size_t			len;

	len = ft_nb_digit(n);
	neg = (n < 0) ? 1 : 0;
	str = ft_strnew(len + neg + 1);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (neg == 1)
	{
		n = -n;
		str[0] = '-';
	}
	str[len + neg] = '\0';
	ft_num_to_char(str, n, len, neg);
	return (str);
}
