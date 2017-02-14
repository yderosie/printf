/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:17:13 by yderosie          #+#    #+#             */
/*   Updated: 2015/01/27 00:56:46 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(char const *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t		ft_strlen_w(wchar_t const *s)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] <= 0x7F)
			len += 1;
		else if (s[i] <= 0x7FF)
			len += 2;
		else if (s[i] <= 0xFFFF)
			len += 3;
		else
			len += 4;
		i++;
	}
	return (len);
}
