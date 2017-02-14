/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:06:33 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/23 12:06:34 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		if_forest_hexa_x(unsigned int k)
{
	if (k < 10)
		return (k + '0');
	else if (k == 10)
		return ('A');
	else if (k == 11)
		return ('B');
	else if (k == 12)
		return ('C');
	else if (k == 13)
		return ('D');
	else if (k == 14)
		return ('E');
	else
		return ('F');
}

static char		if_forest_hexa(unsigned int k)
{
	if (k < 10)
		return (k + '0');
	else if (k == 10)
		return ('a');
	else if (k == 11)
		return ('b');
	else if (k == 12)
		return ('c');
	else if (k == 13)
		return ('d');
	else if (k == 14)
		return ('e');
	else
		return ('f');
}

char			*conv_hexa_x(t_ull j)
{
	char			*s1;
	int				i;
	t_ull			k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_hexa(j)));
	ft_bzero(s1, count_c_hexa(j));
	while (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa_x(k);
		i++;
	}
	s1[i] = if_forest_hexa_x(j);
	s2 = ft_inverse(s1);
	return (s2);
}

char			*conv_hexa(t_ull j)
{
	char			*s1;
	int				i;
	t_ull			k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * count_c_hexa(j));
	ft_bzero(s1, count_c_hexa(j));
	while (j >= 16)
	{
		k = j;
		j = j / 16;
		k = (k % 16);
		s1[i] = if_forest_hexa(k);
		i++;
	}
	s1[i] = if_forest_hexa(j);
	s2 = ft_inverse(s1);
	free(s1);
	return (s2);
}

unsigned int	count_c_hexa(t_ull i)
{
	t_ull	j;
	t_ull	k;

	j = 0;
	while (i >= 16)
	{
		k = i;
		i = i / 16;
		k = (k % 16);
		j++;
	}
	j += 2;
	return (j);
}
