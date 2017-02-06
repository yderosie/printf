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

int		diff_p(int precision, int len, int negatif)
{
	int ret;

	ret = precision - len;
	ret = (negatif) ? ret + 1 : ret;
	ret = (ret > 0) ? ret : 0;
	return (ret);
}

int		len_cw(wchar_t c, unsigned int ret, t_flags flags)
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

int		diff_sw(wchar_t *s, t_flags flags)
{
	int len;
	int i;

	len = 0;
	i = 1;
	if (len_cw(s[0], len, flags) <= flags.p)
	{
		len = len_cw(s[0], len, flags);
		while (s[i] != '\0' && len <= flags.p)
		{
			len = len_cw(s[i++], len, flags);
		}
		if (len > flags.p)
		{
			len = len - len_cw(s[i - 1], 0, flags);
			return (flags.p + (len - flags.p));
		}
	}
	return (flags.p);
}
