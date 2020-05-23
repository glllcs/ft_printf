/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:27:27 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/23 19:57:53 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c;
	int	i;
	char	*p = "palavra";
//	float	decimal;

	c = 'x';
	i = 47;
	ft_printf("elemento %c %c\n", c, i);
	printf("elemento %c %c\n", c, i);
	printf("\n");
	ft_printf("aqui a string %c %c\n", p, i);
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
