/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/28 00:42:48 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:41:33 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modul(t_precis *nb, t_flag *flag, char *format, int *len)
{
	distrib(nb, flag, format);
	nb->j = double_modulo(nb, format);
	if (nb->min != 0)
		*len += nb->min;
	else
		(*len)++;
}

void	distrib(t_precis *nb, t_flag *flag, char *format)
{
	init(flag, nb);
	stop_convers(format, nb);
	check_flags(format, nb);
	check_precis(nb, format);
}

int		check_convers_null(int *len)
{
	if (*len == -2 || *len != 0)
	{
		if (*len == -2)
			*len = 0;
		return (1);
	}
	else
		return (0);
}

int		false_convers2(t_precis *nb, char c)
{
	if (nb->precis != 0)
		return (useles_char(nb, c) - 1);
	else
		ft_putchar(c);
	return (0);
}

int		conv_ls_null(int i)
{
	i = 0;
	ft_putstr("(null)");
	return (6);
}
