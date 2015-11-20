/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 06:37:21 by dmathe            #+#    #+#             */
/*   Updated: 2015/02/08 06:37:35 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init(t_flag *flag, t_precis *nb)
{
	init_precis(nb);
	init_flag(flag);
}

void			init_precis(t_precis *nb)
{
	nb->pt = 0;
	nb->min = 0;
	nb->max = 0;
	nb->point = 0;
	nb->precis = 0;
	nb->hash = 0;
	nb->moins = 0;
	nb->plus = 0;
	nb->space = 0;
	nb->zero = 0;
	nb->negatif = 0;
	nb->convers = 0;
	nb->lim = 0;
}

int				precis_min(t_precis *nb, char *str)
{
	int			j;
	int			i;
	char		*tmp;

	i = nb->j;
	j = 0;
	tmp = (char *)ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0' && str[i] != '.' && i <= nb->convers)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	nb->min = ft_atoi(tmp);
	nb->point = i;
	free(tmp);
	return ((nb->min == 0) ? 0 : 1);
}

int				precis_max(t_precis *nb, char *str)
{
	int			i;
	int			j;
	char		*tmp;

	j = 0;
	i = nb->point + 1;
	tmp = (char *)ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0' && i <= nb->convers)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	nb->max = ft_atoi(tmp);
	free(tmp);
	return ((nb->max == 0) ? 0 : 1);
}

void			check_precis(t_precis *nb, char *str)
{
	nb->precis += precis_min(nb, str);
	nb->precis += precis_max(nb, str);
}
