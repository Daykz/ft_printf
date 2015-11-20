/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathe <dmathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 19:53:28 by dmathe            #+#    #+#             */
/*   Updated: 2015/04/28 05:14:40 by dmathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*displaywchar(char **tab, int nb)
{
	int		tmp[nb];
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = -1;
	str = (char *)ft_memalloc(sizeof(char) * 4092);
	while (++i <= nb)
		tmp[i] = basedecimal(tab[i]);
	i = 0;
	while (i <= nb)
	{
		str[j] = tmp[i];
		i++;
		j++;
	}
	free(str);
	return (str);
}

char		*splitbinary(char *bin, int nbdiv)
{
	char	*tab[8];
	int		i;
	int		j;
	int		ct;
	int		div;

	i = 0;
	ct = 0;
	div = 8;
	while (ct < nbdiv)
	{
		j = 0;
		tab[ct] = (char *)malloc(sizeof(char) * 8 + 1);
		while (i < div)
			tab[ct][j++] = bin[i++];
		tab[ct][j] = '\0';
		ct++;
		div += 8;
	}
	return (displaywchar(tab, (ct - 1)));
}

char		*fillmask(char *bin, char *tmp, int masklen)
{
	int		i;
	int		j;

	i = 0;
	j = masklen - 1;
	while (j >= 0)
	{
		if (tmp[i] == 'x')
		{
			tmp[i] = bin[j];
			j--;
		}
		i++;
	}
	tmp = ft_strrev(tmp);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == 'x')
			tmp[i] = '0';
		i++;
	}
	return (splitbinary(tmp, (ft_strlen(tmp) / 8)));
}

char		*maskunicode(char *bin, int masklen)
{
	char	*tab[4];
	char	*tmp;
	int		len;

	len = 0;
	tab[0] = "0xxxxxxx";
	tab[1] = "110xxxxx10xxxxxx";
	tab[2] = "1110xxxx10xxxxxx10xxxxxx";
	tab[3] = "11110xxx10xxxxxx10xxxxxx10xxxxxx";
	if (masklen > 7 && masklen <= 11)
	{
		tmp = ft_strrev(tab[1]);
		len = 2;
	}
	else if (masklen > 11 && masklen <= 16)
	{
		tmp = ft_strrev(tab[2]);
		len = 3;
	}
	else
	{
		tmp = ft_strrev(tab[3]);
		len = 4;
	}
	return (fillmask(bin, tmp, masklen));
}

int			printwchar(int tmp, char *newstr, t_precis *nb)
{
	char	*bin;
	int		len;
	char	*str;

	len = 0;
	str = (char *)ft_memalloc(sizeof(char) * 4092);
	bin = basebinary(tmp);
	if ((int)ft_strlen(bin) <= 7 && max_wchar(nb, ft_strlen(bin)) == 1)
	{
		str = (char *)&tmp;
		newstr = ft_strcat(newstr, str);
		return (1);
	}
	else if (max_wchar(nb, ft_strlen(bin)) == 1)
	{
		str = maskunicode(bin, ft_strlen(bin));
		newstr = ft_strcat(newstr, str);
		len = ft_strlen(str);
		return (len);
	}
	return (0);
}
