/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_len2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 19:38:07 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:00:20 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				u_len_j(va_list ap, t_precis *nb)
{
	char		*str;
	uintmax_t	n;
	int			len;

	len = 0;
	n = va_arg(ap, uintmax_t);
	str = ft_lutoa((uintmax_t)n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int				u_len_z(va_list ap, t_precis *nb)
{
	char		*str;
	size_t		n;
	int			len;

	len = 0;
	n = va_arg(ap, size_t);
	str = ft_sizeutoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
