/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderosie <yderosie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 23:04:41 by yderosie          #+#    #+#             */
/*   Updated: 2017/02/14 16:47:54 by yderosie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/include/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{
//	char *s1;
//	char **s2;
//	ull i = 48000000000;
//	int *b = &i;
//	int	j;
//	j = 0;
//	s1 = "11111111       00000000 10101010";
//	printf("%");
//	printf("%d\n", ft_printf("{%010d}", -42));
/*	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\
%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
'.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
'<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');*/
//	ft_printf("{%0-3d}",0);
//	printf("%d\n",ft_printf("{%15.4d}", 424242));
//	ft_printf("%15.4d", -42);
//	ft_printf("%-10s is a string\n", "this");
//	ft_printf("%5c\n", 42);
//	printf("%5c\n", 42);
//	printf("%-10s is a string\n", "this");
//	ft_printf("%-5.2s is a string\n", "this");
//	printf("%-5.2s is a string\n", "this");

	ft_printf("%0 d\n", 42);
//	ft_printf("%-05%\n");
//	printf("%-05%\n");
//	ft_printf("% 10.5d\n", 4242);
//	printf("% 10.5d\n", 4242);
//	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	ft_printf("%#-08x\n", 42);
//	printf("%#-08x\n", 42);
//	ft_printf("%#08x\n", 42);
//	printf("%#08x\n", 42);

//	ft_printf("%#8x\n", 42);
// 	printf("%#8x\n", 42);

//	ft_printf("%5.2x\n", 5427);
//	printf("%5.2x\n", 5427);
//	ft_printf("%-5o\n", 2500);
//	printf("%-5o\n", 2500);
//	ft_printf("%05o\n", 42);
//	printf("%05o\n", 42);
//	ft_printf("%5o\n", 41);
//	printf("%5o\n", 41);
//	ft_printf("%-5c\n", 42);
//	printf("%-5c\n", 42);

//	ft_printf("%-15x\n", 542);
//	printf("%-15x\n", 542);
//	ft_printf("%-5%");
//	printf("%-5%");
//	ft_printf("%.4u", 42);
//	ft_printf("%+03d", 0);
//	ft_printf("%4.15x", 42424242);
//	ft_printf("%+d", 42);
//	printf("%+d", 42);
//	printf("%s\n", 1);
//	ft_printf("%lo, %lo\n", 0, 18446744073709551615);
//	printf("%lo, %lo\n", 0, 18446744073709551615);
//	printf("\n");
//	ft_printf("% Zoooo\n");
//	ft_printf("%030S", L"我是一只猫。");
//	ft_printf("{%05.Z}", 0);
//	ft_printf("{ft_printf == %015D}\n", 20);
//	printf("{printf == %015D}\n", 20);
//	printf("%D\n", LONG_MIN);
//	ft_printf("%D\n", LONG_MIN);
/*	ft_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
		L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
		L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");*/
//	ft_printf("%o\n", 999988888);
//	ft_printf("[ft_printf == %u%u%u%u%u\n]", 1, 10, 999, 42, 999988888);
//	printf("{printf == %u%u%u%u%u\n}", 1, 10, 999, 42, 999988888);
//	printf("pr = [%d]\n", ft_printf("%p", &i));
//	printf("pr = [%d]\n", printf("%p", &i));
//	printf("pr = [%d\n]", printf("%s\n", 0));
//	printf("fpr = [%d\n]", ft_printf("%s\n", 0));
//	ft_printf("qwe%s\n%hdr%lut%%yu\n%#X\ni%Sop\n", "test", 123, 400000, 4048, L"我是一只猫。");
//	printf("qwe%s\n%hdr%lut%%yu\n%#X\ni%Sop\n", "test", 123, 400000, 4048, L"我是一只猫。");
//	printf("printf = %%\n");
//	printf("test = %%\n");
//	printf("test S = %S\n", L"test");
//	ft_printf("ft test p = %p\n", b);
//	printf("test p = %p\n", b);
//	printf("%#x\n", b);
//	printf("%p\n", b);
//	ft_printf("%#x\n", b);
//	ft_printf("%p\n", b);
//	ft_printf("ft_printf = %%\n");
//	ft_printf("%o\n", 10208);
//	printf("%o\n", 10208);
//	ft_printf("%i\n", -1111111);
//	printf("%i\n", -4545453);
	return (0);
}
