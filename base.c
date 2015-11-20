/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 19:46:43 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:45:01 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			strprecis(t_precis *nb, int *i, int *x, int *j)
{
	if (nb->min > *i)
	{
		*x = nb->min - *i;
		while (*j < *x)
		{
			ft_putchar(' ');
			(*j)++;
		}
	}
}

void			put_char(char c, int *len)
{
	ft_putchar(c);
	(*len)++;
}

void			modul_alo(t_precis *nb, t_flag *flag, char *format)
{
	distrib(nb, flag, format);
	check_modif_len(flag, format, nb);
}

char			*basebinary(int n)
{
	char		*ret;
	int			i;
	int			tmp;

	tmp = n;
	i = 0;
	while (tmp >= 2)
	{
		tmp = tmp / 2;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * i + 1);
	if (ret)
	{
		ret[i + 1] = '\0';
		while (i >= 0)
		{
			tmp = n % 2;
			ret[i] = 48 + tmp;
			n = n / 2;
			i--;
		}
	}
	return (ret);
}

int				basedecimal(char *bin)
{
	int			tab[7];
	int			i;
	int			j;
	int			ret;

	i = 1;
	j = 0;
	tab[0] = 1;
	ret = 0;
	while (i < 8)
	{
		tab[i] = tab[i - 1] * 2;
		i++;
	}
	while (j < 8)
	{
		if (bin[j] == '1')
			ret += tab[i - 1];
		i--;
		j++;
	}
	return (ret);
}
