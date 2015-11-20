/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_len2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 16:37:13 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:38:38 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					di_len(va_list ap, t_precis *nb)
{
	int				n;
	char			*str;
	int				len;

	len = 0;
	n = va_arg(ap, int);
	str = ft_itoa(n);
	len = check_precision(str, nb, n);
	if (len > 1)
		return (len);
	if (nb->zero == 1 && nb->pt == 0 && nb->moins == 1)
		return (zero_with_less(nb));
	else if (nb->pt == 1 && nb->precis == 0 && n == 0)
		return (-2);
	else if (nb->precis != 0)
		return (ft_intprecis(str, nb));
	else if (nb->precis == 0)
	{
		ft_putstr(str);
		return (ft_strlen(str) + len);
	}
	return (0);
}

int					di_len_z(va_list ap, t_precis *nb)
{
	size_t			n;
	char			*str;
	long long int	len;

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
		return (ft_intprecis(str, nb));
	else
		ft_putstr(str);
	return (ft_strlen(str));
}

int					di_len_j(va_list ap, t_precis *nb)
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
