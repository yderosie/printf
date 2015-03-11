/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 23:04:41 by yderosie          #+#    #+#             */
/*   Updated: 2015/02/17 16:34:26 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
//	char *s1;
//	char **s2;
	int i = 48;
	int *b = &i;
//	int	j;
//	j = 0;
//	s1 = "11111111       00000000 10101010";
//	printf("pr = [%d\n]", printf("%s\n", 0));
//	printf("pr = [%d\n]", printf("%s\n", 0));
//	printf("pr = [%d\n]", printf("%s\n", 0));
//	printf("fpr = [%d\n]", ft_printf("%s\n", 0));
	ft_printf("qwe%s\n%hdr%lut%%yu\n%#X\ni%Sop\n", "test", 1230000, 4000000000, 4048, L"我是一只猫。"/*, argv[2], argv[3], argv[4]*/);
	printf("qwe%s\n%hdr%lut%%yu\n%#X\ni%Sop\n", "test", 1230000, 4000000000, 4048, L"我是一只猫。"/*, argv[2], argv[3], argv[4]*/);
	printf("printf = %%\n");
	printf("test = %%\n");
	printf("test S = %S\n", L"test");
	ft_printf("ft test p = %p\n", b);
	printf("test p = %p\n", b);
//	ft_printf("ft_printf = %%\n");
//	ft_printf("%o\n", 10208);
//	printf("%o\n", 10208);
//	ft_printf("%i\n", -1111111);
//	printf("%i\n", -4545453);
	return (0);
}
