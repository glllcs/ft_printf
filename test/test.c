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
	//char	*p = "palavra";
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
	ft_printf("ft_printf:\n.%10.c.\n", c);
	printf("printf:\n.%10.c.\n", c);
	ft_printf("ft_printf:\n.%-10c.\n", c);
	printf("printf:\n.%-10c.\n", c);
	ft_printf("ft_printf:\n.%*c.\n", 10, c);
	printf("printf:\n.%*c.\n", 10, c);
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
