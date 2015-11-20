/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 02:15:00 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:43:35 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						conv_p(va_list ap, t_precis *nb)
{
	char				*str;
	unsigned long int	n;
	int					len;

	len = 0;
	n = va_arg(ap, long long int);
	str = ft_lhtoa((unsigned long int)n);
	if (nb->min != 0 && nb->moins == 0 && nb->zero == 0)
		len += size_fields_pointer(ft_strlen(str) + 2, nb);
	ft_putstr("0x");
	if (nb->pt == 1 && nb->precis == 0)
		return (2);
	if (nb->max > (int)ft_strlen(str))
		len += intprecis(str, nb);
	if (nb->min > (int)ft_strlen(str) && nb->zero == 1)
		len += zero_for_p(nb);
	ft_putstr(str);
	if (nb->min != 0 && nb->moins == 1)
		len += size_fields_pointer(ft_strlen(str) + 2, nb);
	return (ft_strlen(str) + 2 + len);
}

int						conv_c(va_list ap, t_precis *nb)
{
	char				c;
	int					len;

	len = 0;
	c = (unsigned char)va_arg(ap, int);
	if (nb->precis != 0 && nb->pt == 1 && nb->max == 0)
		return (null_with_precis_c(nb));
	if (nb->zero == 1 && nb->pt == 0)
	{
		len = zero_fill_char(nb);
		ft_putchar(c);
		return (len + 1);
	}
	if (nb->min != 0 && nb->pt == 0)
		len = size_fields_char(nb);
	ft_putchar(c);
	return (len + 1);
}

int						conv_ls(va_list ap, t_precis *nb)
{
	wchar_t				*wc;
	int					i;
	int					len;
	int					tmp;
	char				*str;

	len = 0;
	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * 4092);
	wc = va_arg(ap, wchar_t *);
	if (wc == NULL)
		return (conv_ls_null(i));
	while (wc[i])
	{
		tmp = (int)(wc[i]);
		len += printwchar(tmp, str, nb);
		i++;
	}
	if (nb->precis != 0)
		len += precis_for_wchar(&len, nb, str);
	else
		ft_putstr(str);
	free(str);
	nb->lim = 0;
	return (len);
}

int						conv_lc(va_list ap, t_precis *nb)
{
	wchar_t				wc;
	int					tmp;
	char				*str;
	int					len;

	len = 0;
	str = (char *)ft_memalloc(sizeof(char) * 4092);
	wc = va_arg(ap, wchar_t);
	tmp = (int)wc;
	if (tmp == 0)
		return (1);
	len = printwchar(tmp, str, nb);
	if (nb->precis != 0)
		len += precis_for_wchar(&len, nb, str);
	else
		ft_putstr(str);
	free(str);
	return (len);
}

int						conv_s(va_list ap, t_precis *nb)
{
	char				*str;
	int					len;

	str = va_arg(ap, char *);
	if (str == NULL && nb->precis != 0 && nb->pt == 1)
		return (null_with_precis_s(nb));
	if (nb->zero == 1 && nb->pt == 0 && nb->min > (int)ft_strlen(str))
	{
		len = zero_fill(str, nb);
		return (len);
	}
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (nb->precis != 0)
		return (ft_strprecis(str, nb));
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
