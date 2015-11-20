/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 06:40:19 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:08:31 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*getnbr(char *str)
{
	int			i;
	char		*newstr;
	int			j;

	j = 0;
	i = 0;
	newstr = ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			newstr[j] = str[i];
			j++;
		}
		i++;
	}
	return (newstr);
}

int				ft_strprecis(char *str, t_precis *nb)
{
	int			i;
	char		*newstr;
	int			x;
	int			j;

	i = 0;
	j = 0;
	if (nb->min != 0 && nb->max == 0 && nb->pt == 0)
		return (size_fields_str(str, nb));
	newstr = ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	while (i < nb->max && str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	strprecis(nb, &i, &x, &j);
	ft_putstr(newstr);
	return (ft_strlen(newstr) + j);
}

int				ft_intprecis(char *str, t_precis *nb)
{
	int			x;
	int			len;

	len = 0;
	x = ft_strlen(str);
	if (nb->moins == 1)
	{
		ft_putstr(str);
		if (nb->max >= x)
			len = intprecis(str, nb);
		else if (nb->min > x)
			len = intprec(str, nb);
		return (ft_strlen(str) + len);
	}
	if (nb->max >= x)
		len = intprecis(str, nb);
	else if (nb->min > x)
		len = intprec(str, nb);
	if (str[0] == '-' && nb->pt == 1 && nb->max > x)
		ft_putstr(getnbr(str));
	else
		ft_putstr(str);
	return (ft_strlen(str) + len);
}

int				intprecis(char *str, t_precis *nb)
{
	int			j;
	int			x;
	int			len;

	len = 0;
	j = nb->max;
	x = ft_strlen(str);
	intprecis2(nb, &j, &len, str);
	if (ft_atoi(str) < 0)
	{
		x = x - 1;
		ft_putchar('-');
	}
	while (x < nb->max)
	{
		ft_putchar('0');
		x++;
		len++;
	}
	return (len);
}

int				intprec(char *str, t_precis *nb)
{
	int			x;
	int			len;

	len = 0;
	x = ft_strlen(str);
	while (x < nb->min)
	{
		ft_putchar(' ');
		x++;
		len++;
	}
	return (len);
}
