/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:40:05 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/03 21:47:52 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_traitement(char *s, unsigned int j)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			j = (j * 10) + (s[i] - '0');
			i++;
		}
		else if (((s[i] == ' ' && j == '\0') || ((s[i] == '-' && j == '\0') &&
					(s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] != '0'))
						|| ((s[i] == '+' && j == '\0') && (s[i + 1] >= '0' &&
							s[i + 1] <= '9')) || ((s[i] >= 9 && s[i] <= 13) &&
								j == '\0')) && (s[i - 1] != '0'))
			i++;
		else
			break ;
	}
	return (j);
}

int					ft_atoi(char const *str)
{
	char			*s;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	s = (char*)str;
	j = ft_traitement(s, i);
	return (j);
}
