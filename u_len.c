/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 19:15:45 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:03:00 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							u_len(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned int			n;
	int						len;

	len = 0;
	n = va_arg(ap, unsigned int);
	str = ft_utoa(n);
	if (nb->pt == 1 && nb->precis == 0)
		return (-2);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int							u_len_h(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned short int		n;
	int						len;

	len = 0;
	n = (unsigned short)va_arg(ap, int);
	str = ft_sutoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int							u_len_hh(va_list ap)
{
	int						n;
	char					*str;
	int						i;

	i = 0;
	n = va_arg(ap, int);
	n = uchar_limit(n);
	str = ft_itoa(n);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int							u_len_l(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned long int		n;
	int						len;

	len = 0;
	n = va_arg(ap, unsigned long int);
	str = ft_lutoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int							u_len_ll(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned long long int	n;
	int						len;

	len = 0;
	n = va_arg(ap, unsigned long long int);
	str = ft_lutoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
