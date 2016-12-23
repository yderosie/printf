/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:37:12 by yderosie          #+#    #+#             */
/*   Updated: 2014/11/09 19:51:44 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	int i;
	int rt;

	i = 0;
	rt = 0;
	while (s != NULL && s[i] != '\0')
	{
		rt += ft_putchar(s[i]);
		i++;
	}
	return (rt);
}
