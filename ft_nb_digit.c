/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 16:24:09 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/16 16:24:11 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nb_digit_uli(uli i, t_flags flags)
{
	int	j;

	j = 0;
	while (i > 10)
	{
		i = i / 10;
		j++;
	}
	j++;
	while (j < flags.precision)
	{
		ft_putchar('0');
		j++;
	}
}

void	ft_nb_digit_u(unsigned int i, t_flags flags)
{
	int	j;

	j = 0;
	while (i > 10)
	{
		i = i / 10;
		j++;
	}
	j++;
	while (j < flags.precision)
	{
		ft_putchar('0');
		j++;
	}
}

void	ft_nb_digit(int i, t_flags flags)
{
	int		j;

	j = 0;
	while (i > 10)
	{
		i = i / 10;
		j++;
	}
	j++;
	while (j < flags.precision)
	{
		ft_putchar('0');
		j++;
	}
}

void	ft_nb_digit_c(char *s, t_flags flags)
{
	int	i;

	i = ft_strlen(s);
	while (i < flags.precision)
	{
		ft_putchar('0');
		i++;
	}
}