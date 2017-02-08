/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:07:43 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/23 12:07:44 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_inverse(char *s)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = ft_strlen(s) - 1;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s));
	while (j >= 0)
	{
		s2[i] = s[j];
		i++;
		j--;
	}
	s2[i] = '\0';
	return (s2);
}

char	*conv_octal(t_ull j)
{
	t_ull	remainder;
	char	*s1;
	int		i;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * 40);
	s1[0] = '0';
	while (j != 0)
	{
		remainder = j % 8;
		j = j / 8;
		if (remainder == 0)
			s1[i++] = '0';
		else
			s1[i++] = remainder + '0';
	}
	s1 = ft_inverse(s1);
	return (s1);
}
