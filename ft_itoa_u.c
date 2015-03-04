/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 10:32:52 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/16 10:32:53 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_nbr(unsigned int n, unsigned int *i)
{
	char	*s2;
	size_t	j;
	size_t	m;
	size_t	save;

	save = n;
	j = save;
	m = save;
	s2 = (char *)malloc(sizeof(*s2) * (1 + 11));
	if (s2 == NULL)
		return (NULL);
	if (save == 0)
	{
		s2[*i] = save + '0';
		++(*i);
		return (s2);
	}
	while (j > 0)
	{
		m = j % 10;
		s2[*i] = m + '0';
		j = j / 10;
		++(*i);
	}
	return (s2);
}

char			*ft_itoa_u(unsigned int n)
{
	unsigned int	i;
	unsigned int	k;
	char			*s1;
	char			*s2;

		i = 0;
		k = 0;
		s2 = ft_nbr(n, &i);
		s1 = (char *)malloc(sizeof(*s1) * (1 + 11));
		if (s1 == NULL || s2 == NULL)
			return (NULL);
		while (i > 0)
			s1[k++] = s2[--i];
		s1[k] = '\0';
		return (s1);
}