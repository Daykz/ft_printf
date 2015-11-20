/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 23:56:59 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:46:05 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_convers(t_flag *flag, va_list ap, char *s, t_precis *nb)
{
	int			len;
	int			j;

	len = 0;
	j = nb->j;
	while (s[j] != '\0')
	{
		len += check_convers1(flag, ap, s[j], nb);
		len += check_convers2(flag, ap, s[j], nb);
		len += check_convers3(flag, ap, s[j], nb);
		len += check_convers4(ap, s[j], nb);
		len += check_convers5(ap, s[j], nb);
		if (false_convers(s[j]) == 1)
		{
			len += false_convers2(nb, s[j]);
			len++;
			break ;
		}
		if (check_convers_null(&len) == 1)
			break ;
		j++;
	}
	nb->j = j;
	return (len);
}

int				check_modif_len(t_flag *flag, char *str, t_precis *nb)
{
	int			i;

	i = nb->j + 1;
	while (str[i] != '\0' && i <= nb->convers)
	{
		if (str[i] == 'h' && str[i - 1] != 'h' && str[i + 1] != 'h')
			flag->h = 1;
		else if (str[i] == 'l' && str[i - 1] != 'l' && str[i + 1] != 'l')
			flag->l = 1;
		else if (str[i] == 'j')
			flag->j = 1;
		else if (str[i] == 'z')
			flag->z = 1;
		else if (str[i] == 'l' && str[i + 1] == 'l')
			flag->ll = 1;
		else if (str[i] == 'h' && str[i + 1] == 'h')
			flag->hh = 1;
		i++;
	}
	return (0);
}

int				check_flags(char *flag, t_precis *nb)
{
	int			i;

	i = nb->j;
	while (flag[i] != '\0' && i <= nb->convers)
	{
		if (flag[i] == '-')
			nb->moins = 1;
		if (flag[i] == '+')
			nb->plus = 1;
		if (flag[i] == ' ')
			nb->space = 1;
		if (flag[nb->j + 1] == '0' || (flag[nb->j + 2] == '0' &&
				(nb->moins == 1 || nb->plus == 1 || nb->hash == 1 ||
				nb->space == 1)))
			nb->zero = 1;
		if (flag[i] == '#')
			nb->hash = 1;
		if (flag[i] == '.')
			nb->pt = 1;
		i++;
	}
	return (0);
}

int				ft_printf(char *format, ...)
{
	char		*tmp;
	t_precis	nb;
	t_flag		flag;
	va_list		ap;
	int			len;

	va_start(ap, format);
	tmp = format;
	len = 0;
	nb.j = -1;
	while (nb.j++ < (int)ft_strlen(format) - 1)
	{
		if (tmp[nb.j] == '%' && check_double_modulo(format, &nb) == 1)
			modul(&nb, &flag, format, &len);
		else if (tmp[nb.j] == '%' && tmp[nb.j + 1] != '\0')
		{
			modul_alo(&nb, &flag, format);
			len += check_convers(&flag, ap, format, &nb);
		}
		else if ((tmp[nb.j] != '%' && ft_strlen(format) != 1) ||
				(tmp[nb.j] != '%' && ft_strlen(format) == 1))
			put_char(tmp[nb.j], &len);
	}
	va_end(ap);
	return (len);
}
