/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 11:41:55 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/23 11:41:58 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	count_c_bin(unsigned int i)
{
	unsigned int	j;
	unsigned int	k;

	j = 0;
	while (i >= 2)
	{
		k = i;
		i = i / 2;
		k = (k % 2);
		j++;
	}
	j += 2;
	return (j);
}

size_t			binary_to_decimal(char *s)
{
	char	*s1;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	k = 0;
	l = 1;
	s1 = ft_inverse(s);
	while (s1[i] != '\0')
	{
		if (s1[i] == '1')
		{
			while (k < i)
			{
				l = l * 2;
				k++;
			}
			j = j + l;
		}
		i++;
	}
	return (write(1, &j, 1));
}

char			*binary(unsigned int j)
{
	char			*s1;
	int				i;
	unsigned int	k;
	char			*s2;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (count_c_bin(j)));
	while (j >= 2)
	{
		k = j;
		j = j / 2;
		k = (k % 2);
		s1[i] = k + '0';
		i++;
	}
	s1[i] = j + '0';
	s2 = ft_inverse(s1);
	return (s2);
}
