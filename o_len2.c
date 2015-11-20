/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouxx_len2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 18:47:30 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:09:26 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				o_len_j(va_list ap, t_precis *nb)
{
	uintmax_t	n;
	char		*str;
	int			len;

	len = 0;
	n = va_arg(ap, uintmax_t);
	str = ft_motoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int				o_len_z(va_list ap, t_precis *nb)
{
	char		*str;
	size_t		n;
	int			len;

	len = 0;
	n = va_arg(ap, size_t);
	str = ft_sizeotoa(n);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
