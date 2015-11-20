/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 03:47:34 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:12:20 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_xmaj(va_list ap, t_flag *flag, t_precis *nb)
{
	int		len;

	len = 0;
	if (flag->h == 1)
		len = xmaj_len_h(ap, nb);
	else if (flag->hh == 1)
		len = xmaj_len_hh(ap);
	else if (flag->l == 1)
		len = xmaj_len_l(ap, nb);
	else if (flag->ll == 1)
		len = xmaj_len_ll(ap, nb);
	else if (flag->j == 1)
		len = xmaj_len_j(ap, nb);
	else if (flag->z == 1)
		len = xmaj_len_z(ap, nb);
	else
		len = xmaj_len(ap, nb);
	return (len);
}

int			conv_di(va_list ap, t_flag *flag, t_precis *nb)
{
	int		len;

	len = 0;
	if (flag->h == 1)
		len = di_len_h(ap, nb);
	else if (flag->hh == 1)
	{
		len += di_len_hh(ap, nb);
		if (len == -1)
		{
			ft_putstr("-1");
			len = 2;
		}
	}
	else if (flag->l == 1)
		len = di_len_l(ap, nb);
	else if (flag->ll == 1)
		len = di_len_ll(ap, nb);
	else if (flag->j == 1)
		len = di_len_j(ap, nb);
	else if (flag->z == 1)
		len = di_len_z(ap, nb);
	else
		len = di_len(ap, nb);
	return (len);
}

int			conv_o(va_list ap, t_flag *flag, t_precis *nb)
{
	int		len;

	len = 0;
	if (flag->h == 1)
		len = o_len_h(ap, nb);
	else if (flag->hh == 1)
		len = o_len_hh(ap);
	else if (flag->l == 1)
		len = o_len_l(ap, nb);
	else if (flag->ll == 1)
		len = o_len_ll(ap, nb);
	else if (flag->j == 1)
		len = o_len_j(ap, nb);
	else if (flag->z == 1)
		len = o_len_z(ap, nb);
	else
		len = o_len(ap, nb);
	return (len);
}

int			conv_u(va_list ap, t_flag *flag, t_precis *nb)
{
	int		len;

	len = 0;
	if (flag->h == 1)
		len = u_len_h(ap, nb);
	else if (flag->hh == 1)
		len = u_len_hh(ap);
	else if (flag->l == 1)
		len = u_len_l(ap, nb);
	else if (flag->ll == 1)
		len = u_len_ll(ap, nb);
	else if (flag->j == 1)
		len = u_len_j(ap, nb);
	else if (flag->z == 1)
		len = u_len_z(ap, nb);
	else
		len = u_len(ap, nb);
	return (len);
}

int			conv_x(va_list ap, t_flag *flag, t_precis *nb)
{
	int		len;

	len = 0;
	if (flag->h == 1)
		len = x_len_h(ap, nb);
	else if (flag->hh == 1)
		len = x_len_hh(ap);
	else if (flag->l == 1)
		len = x_len_l(ap, nb);
	else if (flag->ll == 1)
		len = x_len_ll(ap, nb);
	else if (flag->j == 1)
		len = x_len_j(ap, nb);
	else if (flag->z == 1)
		len = x_len_z(ap, nb);
	else
		len = x_len(ap, nb);
	return (len);
}
