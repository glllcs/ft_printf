/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 08:27:27 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/23 09:16:09 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/ft_printf.h"

int	main(void)
{
	int	inteiro;
	float	decimal;

	ft_printf("abacate");

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
	/*decimal = -44.65;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = 490904.656565;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = -490904.656565;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);*/
	return (0);
}
