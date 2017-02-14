/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:48:39 by yderosie          #+#    #+#             */
/*   Updated: 2017/01/26 16:48:40 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	tab_0(char *s1, char *tab)
{
	int		i;
	int		j;
	int		l;
	char	**s2;
	size_t	ret;

	l = 0;
	ret = 0;
	i = ft_strlen(tab);
	j = ft_strlen(s1) - 1;
	while (j >= 0 && --i >= 0)
	{
		if (tab[i] == 'x')
			tab[i] = s1[j--];
	}
	i = -1;
	while (tab[++i] != '\0')
	{
		if (tab[i] == 'x')
			tab[i] = '0';
	}
	s2 = ft_strsplit(tab, ' ');
	while (s2[l] != '\0')
		ret += binary_to_decimal(s2[l++]);
	return (ret);
}

size_t	nb_octets_write_2(unsigned int i)
{
	char	*tab[3];
	char	*s1;
	char	*s2;

	s2 = (char*)malloc(sizeof(char) * 36);
	ft_bzero(s2, 36);
	tab[0] = "110xxxxx 10xxxxxx\0";
	s2 = ft_strcpy(s2, tab[0]);
	tab[1] = "1110xxxx 10xxxxxx 10xxxxxx\0";
	tab[2] = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx\0";
	s1 = binary(i);
	if (i <= 0x7FF)
		s2 = ft_strcpy(s2, tab[0]);
	else if (i <= 0xFFFF)
		s2 = ft_strcpy(s2, tab[1]);
	else
		s2 = ft_strcpy(s2, tab[2]);
	return (tab_0(s1, s2));
}

size_t	nb_octets_write(wchar_t c)
{
	unsigned int i;

	i = (unsigned int)c;
	if (i <= 0x7F)
		return (ft_putwchar(c));
	else if (i >= 0x7F && i <= 0x1FFFFF)
		return (nb_octets_write_2(i));
	else
		return (-1);
	return (0);
}
