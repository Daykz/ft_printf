/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 23:04:33 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 04:56:30 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							x_len_ll(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned long long int	n;
	int						len;

	len = 0;
	n = va_arg(ap, unsigned long long int);
	str = ft_lhtoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int							x_len_l(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned long int		n;
	int						len;

	len = 0;
	n = va_arg(ap, unsigned long int);
	str = ft_lhtoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int							x_len_hh(va_list ap)
{
	int						n;
	char					*str;
	int						i;

	i = 0;
	n = va_arg(ap, int);
	n = uchar_limit(n);
	str = ft_htoa(n);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int							x_len_h(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned short int		n;
	int						len;

	len = 0;
	n = (unsigned short)va_arg(ap, int);
	str = ft_shtoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int							x_len(va_list ap, t_precis *nb)
{
	char					*str;
	unsigned int			n;
	int						len;

	len = 0;
	n = va_arg(ap, unsigned int);
	if (nb->pt == 1 && nb->precis == 0)
		return (-2);
	str = ft_htoa(n);
	if (nb->zero == 1 && nb->pt == 0 && nb->min > (int)ft_strlen(str))
		return (zero_fill(str, nb));
	if (nb->hash == 1 && n != 0)
	{
		ft_putstr("0x");
		len += 2;
	}
	if (nb->precis != 0)
	{
		len += ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}
