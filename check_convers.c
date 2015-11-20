/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_convers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 00:52:06 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:44:19 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_convers5(va_list ap, char c, t_precis *nb)
{
	if (c == 'O')
		return (o_len_l(ap, nb));
	else if (c == 'U')
		return (u_len_l(ap, nb));
	else
		return (0);
}

int				check_convers4(va_list ap, char c, t_precis *nb)
{
	if (c == 'S')
		return (conv_ls(ap, nb));
	else if (c == 'C')
		return (conv_lc(ap, nb));
	else if (c == 'D')
		return (di_len_l(ap, nb));
	else
		return (0);
}

int				check_convers3(t_flag *flag, va_list ap, char c, t_precis *nb)
{
	if (c == 'u')
		return (conv_u(ap, flag, nb));
	else if (c == 'x')
		return (conv_x(ap, flag, nb));
	else if (c == 'X')
		return (conv_xmaj(ap, flag, nb));
	else
		return (0);
}

int				check_convers2(t_flag *flag, va_list ap, char c, t_precis *nb)
{
	if (c == 'p')
		return (conv_p(ap, nb));
	else if (c == 'd' || c == 'i')
		return (conv_di(ap, flag, nb));
	else if (c == 'o')
		return (conv_o(ap, flag, nb));
	else
		return (0);
}

int				check_convers1(t_flag *flag, va_list ap, char c, t_precis *nb)
{
	if (c == 's')
	{
		if (flag->l == 1)
			return (conv_ls(ap, nb));
		else
			return (conv_s(ap, nb));
	}
	else if (c == 'c')
	{
		if (flag->l == 1)
			return (conv_lc(ap, nb));
		else
			return (conv_c(ap, nb));
	}
	else
		return (0);
}
