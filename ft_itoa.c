/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:11:37 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/06 07:12:18 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_nbr(ll n, ll *i)
{
	char	*s2;
	ll 		j;
	ll		m;
	ll		save;

	save = (n < 0) ? -n : n;
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

char			*ft_itoa(ll n)
{
	ll		i;
	ll		k;
	char	*s1;
	char	*s2;

	i = 0;
	k = 0;
	s2 = ft_nbr(n, &i);
	s1 = (char *)malloc(sizeof(*s1) * (1 + 11));
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (n < 0)
	{
		s1[0] = '-';
		k++;
	}
	while (i >= 0)
		s1[k++] = s2[--i];
	s1[k] = '\0';
	return (s1);
}
