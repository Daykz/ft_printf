/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouxx_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 22:16:32 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:11:21 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int								o_len(va_list ap, t_precis *nb)
{
	unsigned int				n;
	char						*str;
	int							len;

	len = 0;
	n = va_arg(ap, unsigned int);
	if (nb->pt == 1 && nb->precis == 0 && nb->hash == 0)
		return (-2);
	if (nb->hash == 1 && n != 0 && nb->precis == 0)
	{
		ft_putchar('0');
		len++;
	}
	str = ft_otoa(n);
	if (nb->precis != 0)
	{
		len += ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}

int								o_len_h(va_list ap, t_precis *nb)
{
	char						*str;
	unsigned short int			n;
	int							len;

	len = 0;
	n = (unsigned short)va_arg(ap, int);
	str = ft_sotoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int								o_len_hh(va_list ap)
{
	int							n;
	char						*str;
	int							i;

	i = 0;
	n = va_arg(ap, int);
	n = uchar_limit(n);
	str = ft_otoa(n);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int								o_len_l(va_list ap, t_precis *nb)
{
	char						*str;
	unsigned long int			n;
	int							len;

	len = 0;
	n = va_arg(ap, unsigned long int);
	if (nb->pt == 1 && nb->precis == 0 && nb->hash == 0)
		return (-2);
	if (nb->hash == 1 && n != 0)
	{
		ft_putchar('0');
		len++;
	}
	str = ft_lotoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}

int								o_len_ll(va_list ap, t_precis *nb)
{
	char						*str;
	unsigned long long int		n;
	int							len;

	len = 0;
	n = va_arg(ap, unsigned long long int);
	if (nb->hash == 1 && n != 0)
	{
		ft_putchar('0');
		len++;
	}
	str = ft_lotoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}
