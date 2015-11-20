/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 00:43:40 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/29 16:35:15 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_double_modulo(char *str, t_precis *nb)
{
	int				i;

	i = nb->j + 1;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		else if (str[i] == ' ' || str[i] == '.' || ft_isdigit(str[i]) == 1)
			i++;
		else
			return (0);
	}
	return (0);
}

int					double_modulo(t_precis *nb, char *str)
{
	int				i;

	i = nb->j + 1;
	if (str[i] == '%')
	{
		ft_putchar('%');
		return (i);
	}
	while ((str[i] == ' ' || str[i] == '.' || ft_isdigit(str[i]) == 1)
	&& str[i] != '\0')
	{
		i++;
		if (str[i] == '%')
		{
			if (nb->precis != 0 && nb->pt == 1 && nb->max == 0)
				i = null_with_precis_c(nb);
			ft_putchar('%');
			return (i);
		}
	}
	return (0);
}

int					false_convers(char c)
{
	if (c != 's' && c != 'S' && c != 'p' && c != 'd' && c != 'D' && c != 'i'
		&& c != 'o' && c != 'O' && c != 'u' && c != 'U' && c != 'x' && c != 'X'
		&& c != 'c' && c != 'C' && c != '#' && c != '0' && c != '-' && c != '+'
		&& c != '%' && c != 'h' && c != 'l' && c != 'j' && c != 'z' && c != ' '
		&& c != '.' && ft_isdigit(c) == 0)
		return (1);
	else
		return (0);
}

int					stop_convers(char *str, t_precis *nb)
{
	int				i;

	i = nb->j + 1;
	while (str[i])
	{
		if (str[i] == 's' || str[i] == 'S' || str[i] == 'p' || str[i] == 'd'
			|| str[i] == 'D' || str[i] == 'i' || str[i] == 'o' || str[i] == 'O'
			|| str[i] == 'u' || str[i] == 'U' || str[i] == 'x' || str[i] == 'X'
			|| str[i] == 'c' || str[i] == 'C' || str[i] == '%')
		{
			nb->convers = i;
			break ;
		}
		i++;
	}
	nb->convers = i;
	return (0);
}

void				init_flag(t_flag *flag)
{
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->j = 0;
	flag->z = 0;
}
