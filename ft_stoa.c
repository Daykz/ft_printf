/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 19:58:13 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:22:16 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_nb_digit(short int n)
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

static void			ft_num_to_char(char *s, short int n, size_t l, size_t ng)
{
	while (l != 0)
	{
		s[l - 1 + ng] = (n % 10) + '0';
		n /= 10;
		l--;
	}
}

char				*ft_stoa(short int n)
{
	char			*str;
	size_t			neg;
	size_t			len;

	len = ft_nb_digit(n);
	neg = (n < 0) ? 1 : 0;
	str = ft_strnew(len + neg + 1);
	if (n == -32768)
		return (ft_strdup("-32768"));
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
