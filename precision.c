/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:54:35 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/26 16:54:36 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		diff_for_precision(int precision, int len, int negatif)
{
	int ret;

	ret = precision - len;
	ret = (negatif) ? ret + 1 : ret; 
	ret = (ret > 0) ? ret : 0;
	return (ret);
}

int		precision_for_s(wchar_t c, unsigned int ret, t_flags flags)
{
	if (c <= 0x7F)
		ret += 1;
	else if (c <= 0x7FF)
		ret += 2;
	else if (c <= 0xFFFF)
		ret += 3;
	else
		ret += 4;
	return (ret);
}

int		diff_precision_s(wchar_t *s, t_flags flags)
{
	int len;
	int i;

	len = 0;
	i = 1;
	if (precision_for_s(s[0], len, flags) <= flags.precision)
	{
		len = precision_for_s(s[0], len, flags);
		while (s[i] != '\0' && len <= flags.precision)
		{
			len = precision_for_s(s[i++], len, flags);
		}
		if (len > flags.precision)
		{
			len = len - precision_for_s(s[i - 1], 0, flags);
			return (flags.precision + (len - flags.precision));
		}
	}
	return (flags.precision);
}