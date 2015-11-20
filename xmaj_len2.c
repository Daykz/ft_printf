/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmaj_len2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 00:43:40 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 04:49:53 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				xmaj_len_z(va_list ap, t_precis *nb)
{
	char		*str;
	size_t		n;
	int			len;

	len = 0;
	n = va_arg(ap, size_t);
	str = ft_sizehmtoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int				xmaj_len_j(va_list ap, t_precis *nb)
{
	char		*str;
	uintmax_t	n;
	int			len;

	len = 0;
	n = va_arg(ap, uintmax_t);
	str = ft_mhmtoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
