/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:24:43 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/26 16:24:45 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_all_option(char c)
{
	char	*conv;
	int		i;

	i = -1;
	conv = "sSpdDioOuUxXcC%hlj#+ z.-0123456789";
	while (conv[++i])
		if (conv[i] == c)
			return (1);
	return (0);
}

int		check_flags(char c)
{
	char	*conv;
	int		i;

	i = -1;
	conv = "hlj#+ z.-0123456789";
	while (conv[++i])
		if (conv[i] == c)
			return (1);
	return (0);
}

int		check_conv(char c)
{
	char	*conv;
	int		i;

	i = -1;
	conv = "sSpdDioOuUxXcC%";
	while (conv[++i])
		if (conv[i] == c)
			return (1);
	return (0);
}
