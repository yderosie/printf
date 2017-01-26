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

char	*conv_octal(ull j)
{
	ull		remainder;
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
