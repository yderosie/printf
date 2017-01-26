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

void	flags_initialization(t_conv *conv)
{
	conv->flags.zero = 0;
	conv->flags.htag = 0;
	conv->flags.espace = 0;
	conv->flags.moins = 0;
	conv->flags.plus = 0;
	conv->flags.point = 0;
	conv->flags.precision = 0;
	conv->flags.largeur = 0;
	conv->flags.fhh = 0;
	conv->flags.fh = 0;
	conv->flags.fl = 0;
	conv->flags.fll = 0;
	conv->flags.j = 0;
	conv->flags.z = 0;
}

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
