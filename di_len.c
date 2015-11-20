/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 19:09:36 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:40:39 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					di_len_ll(va_list ap, t_precis *nb)
{
	long long int	n;
	char			*str;
	int				len;

	len = 0;
	n = va_arg(ap, long long int);
	str = ft_ltoa(n);
	if (check_precision(str, nb, n) == 1)
		len++;
	else if (check_precision(str, nb, n) == 2)
		return (zero_fill(str, nb));
	if (nb->zero == 1 && nb->pt == 0 && nb->moins == 1)
		return (zero_with_less(nb));
	if (nb->pt == 1 && nb->precis == 0 && n == 0)
		return (0);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int					di_len_l(va_list ap, t_precis *nb)
{
	long int		n;
	char			*str;
	int				len;

	len = 0;
	n = va_arg(ap, long int);
	str = ft_ltoa((long int)n);
	if (check_precision(str, nb, n) == 1)
		len++;
	else if (check_precision(str, nb, n) == 2)
		return (zero_fill(str, nb));
	if (nb->zero == 1 && nb->pt == 0 && nb->moins == 1)
		return (zero_with_less(nb));
	if (nb->pt == 1 && nb->precis == 0 && n == 0)
		return (0);
	if (nb->precis != 0)
	{
		len = ft_intprecis(str, nb);
		return (len);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int					di_len_hh(va_list ap, t_precis *nb)
{
	int				n;
	char			*str;
	int				len;

	len = 0;
	n = va_arg(ap, int);
	if (n == 2147483647)
		return (-1);
	n = char_limit(n);
	str = ft_itoa(n);
	if (check_precision(str, nb, n) == 1)
		len++;
	else if (check_precision(str, nb, n) == 2)
		return (zero_fill(str, nb));
	if (nb->zero == 1 && nb->pt == 0 && nb->moins == 1)
		return (zero_with_less(nb));
	if (nb->pt == 1 && nb->precis == 0 && n == 0)
		return (0);
	if (nb->precis != 0)
		return (ft_intprecis(str, nb));
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}

int					di_len_h(va_list ap, t_precis *nb)
{
	short int		n;
	char			*str;
	int				len;

	len = 0;
	n = (short int)va_arg(ap, int);
	str = ft_stoa(n);
	if (check_precision(str, nb, n) == 1)
		len++;
	else if (check_precision(str, nb, n) == 2)
		return (zero_fill(str, nb));
	if (nb->zero == 1 && nb->pt == 0 && nb->moins == 1)
		return (zero_with_less(nb));
	if (nb->pt == 1 && nb->precis == 0 && n == 0)
		return (0);
	if (nb->precis != 0)
		return (ft_intprecis(str, nb));
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}
