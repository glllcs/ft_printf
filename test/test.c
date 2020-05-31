/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:27:27 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/25 08:09:09 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c;
	int	i;
	char	*p = "palavra";
	float	f;

	c = 'x';
	i = 42;
	f = 43435.456;
//	ft_printf("elemento %c %c\n", c, i);
//	printf("elemento %c %c\n", c, i);
//	printf("\n");
//	ft_printf("aqui a string %c %c\n", p, i);
	//printf("%0s\n", p);
	//printf("\n.% s.\n", p);
	//printf("%+s\n", p);

//	//charactere
	printf("1printf:\t.%10.c.\n", c);
	ft_printf("1ft_printf:\t.%10.c.\n", c);
	printf("\n");
	printf("2printf:\t.%-10c.\n", c);
	ft_printf("2ft_printf:\t.%-10c.\n", c);
	printf("\n");
	printf("3printf:\t.%*c.\n", 10, c);
	ft_printf("3ft_printf:\t.%*c.\n", 10, c);
	printf("\n");
	printf("4printf:\t.%c.\n", c);
	ft_printf("4ft_printf:\t.%c.\n", c);
	printf("\n");
	printf("5printf:\t.%*c.\n", 0, c);
	ft_printf("5ft_printf:\t.%*c.\n", 0, c);
	printf("\n");

	//string
	printf("1printf:\t.%10.s.\n", p);
	ft_printf("1ft_printf:\t.%10.s.\n", p);
	printf("\n");
	printf("2printf:\t.%-10s.\n", p);
	ft_printf("2ft_printf:\t.%-10s.\n", p);
	printf("\n");
	printf("3printf:\t.%*s.\n", 10, p);
	ft_printf("3ft_printf:\t.%*s.\n", 10, p);
	printf("\n");
	printf("4printf:\t.%*.*s.\n", 0, 10, p);
	ft_printf("4ft_printf:\t.%*.*s.\n", 0, 10, p);
	printf("\n");
	printf("5printf:\t.%*.*s.\n", 10, 0, p);
	ft_printf("5ft_printf:\t.%*.*s.\n", 10, 0, p);
	printf("\n");
	printf("6printf:\t.%*.*s.\n", 4, 10, p);
	ft_printf("6ft_printf:\t.%*.*s.\n", 4, 10, p);
	printf("\n");
	printf("7printf:\t.%*.*s.\n", 10, 4, p);
	ft_printf("7ft_printf:\t.%*.*s.\n", 10, 4, p);
	printf("\n");
	printf("8printf:\t.%*.*s.\n", 0, 4, p);
	ft_printf("8ft_printf:\t.%*.*s.\n", 0, 4, p);
	printf("\n");
	printf("9printf:\t.%*.*s.\n", 2, 10, p);
	ft_printf("9ft_printf:\t.%*.*s.\n", 2, 10, p);
	printf("\n");
	printf("10printf:\t.%*.*s.\n", 0, 0, p);
	ft_printf("10ft_printf:\t.%*.*s.\n", 0, 0, p);
	printf("\n");
	printf("11printf:\t.%-*.*s.\n", 10, 4, p);
	ft_printf("11ft_printf:\t.%-*.*s.\n", 10, 4, p);
	printf("\n");
	printf("12printf:\t.%s %c %s %-*.*s?.\n", "cade", 'o', "meu", 10, 4, "cachorrinho");
	ft_printf("12ft_printf:\t.%s %c %s %-*.*s?.\n", "cade", 'o', "meu", 10, 4, "cachorrinho");

//	printf(".%10.4c.\n", c);
//	printf("\n");
//	printf("%+010%");
//	printf("\n");
//	printf("%d %0d %-d %.2d\n", i, i ,i, i);
//	printf(". %-10d .\n", i);
//    printf(". %00010d .\n", i);
//    printf(". %- 10d .\n", i);
//    printf(". % -10d .\n", i);
//    printf(". %-#10x .\n", i);  
//    printf(". %#x .\n", i);
//    printf(". %*d .\n", 10, i);
//    printf(". %10.2f .\n", f);
	//printf("%f %0f %-f %.20f %'f", f, f, f, f, f);

	//printf("aqui a string %s %c\n", p, i);
/*
	printf("INT\n");
	inteiro = 44;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	inteiro = -44;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	inteiro = 490904;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	inteiro = -490904;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	printf("\nDOUBLE\n");
	decimal = 44.65;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%.f, %%.0f=%.0f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = -44.65;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = 490904.656565;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = -490904.656565;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);*/
	return (0);
}
