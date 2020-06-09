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

void	test_c(void)
{
	char	c = 'x';

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
	printf("5printf:\t.%*c.\n", 0, 0);
	ft_printf("5ft_printf:\t.%*c.\n", 0, 0);
	printf("\n");
	printf("6printf:\t.%c.\n", '\0');
	ft_printf("6ft_printf:\t.%c.\n", '\0');
	printf("\n");
}

void	test_s(void)
{
	char	*p = "palavra";

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
	printf("\n");
	printf("13printf:\t.%s.\n", NULL);
	//ft_printf("13ft_printf:\t.%s.\n", NULL);
	printf("\n");
	printf("14printf:\t.%10s.\n", NULL);
	ft_printf("14ft_printf:\t.%10s.\n", NULL);
}

void	test_p(void)
{
	char	*p = "palavra";

//	printf("%s", ft_itoa_base_u(4294978743, BASE_HEX));
	printf("1printf:\t.%.p.\n", p);
	ft_printf("1ft_printf:\t.%.p.\n", p);
	printf("\n");
	printf("2printf:\t.%-15p.\n", p);
	ft_printf("2ft_printf:\t.%-15p.\n", p);
	printf("\n");
	printf("3printf:\t.%15p.\n", p);
	ft_printf("3ft_printf:\t.%15p.\n", p);
	printf("\n");
	printf("4printf:\t.%9p.\n", p);
	ft_printf("4ft_printf:\t.%9p.\n", p);
	printf("\n");
	printf("5printf:\t.%p.\n", NULL);
	ft_printf("5ft_printf:\t.%p.\n", NULL);
	printf("\n");
	printf("6printf:\t.%5.p.\n", NULL);
	ft_printf("6ft_printf:\t.%5.p.\n", NULL);
	printf("\n");
	printf("7printf:\t.%2.p.\n", NULL);
	ft_printf("7ft_printf:\t.%2.p.\n", NULL);
	printf("\n");
}

void	test_pct(void)
{
	printf("1printf:\t.%+%.\n");
	ft_printf("1ft_printf:\t.%+%.\n");
	printf("\n");
	printf("2printf:\t.%-10%.\n");
	ft_printf("2ft_printf:\t.%-10%.\n");
	printf("\n");
	printf("3printf:\t.%0%.\n");
	ft_printf("3ft_printf:\t.%0%.\n");
	printf("\n");
	printf("4printf:\t.% %.\n");
	ft_printf("4ft_printf:\t.% %.\n");
	printf("\n");
	printf("5printf:\t.%.%.\n");
	ft_printf("5ft_printf:\t.%.%.\n");
	printf("\n");
	printf("6printf:\t.%.5%.\n");
	ft_printf("6ft_printf:\t.%.5%.\n");
	printf("\n");
	printf("7printf:\t.%+15%.\n");
	ft_printf("7ft_printf:\t.%+15%.\n");
	printf("\n");
	printf("8printf:\t.%6.7%.\n");
	ft_printf("8ft_printf:\t.%6.7%.\n");
	printf("\n");
}

void	test_d(void)
{
	printf("1printf:\t.%+1d.\n", 0);
	ft_printf("1ft_printf:\t.%+1d.\n", 0);
	printf("\n");
	printf("2printf:\t.% 04d.\n", 5);
	ft_printf("2ft_printf:\t.% 04d.\n", 5);
	printf("\n");
	printf("3printf:\t.%05d.\n", 42);
	ft_printf("3ft_printf:\t.%05d.\n", 42);
	printf("\n");
	printf("4printf:\t.%- 8d.\n", -42);
	ft_printf("4ft_printf:\t.%- 8d.\n", -42);
	printf("\n");
	printf("5printf:\t.%.d.\n", 42);
	ft_printf("5ft_printf:\t.%.d.\n", 42);
	printf("\n");
	printf("6printf:\t.%2.5d.\n", -42);
	ft_printf("6ft_printf:\t.%2.5d.\n", -42);
	printf("\n");
	printf("7printf:\t.%015d.\n", -42);
	ft_printf("7ft_printf:\t.%015d.\n", -42);
	printf("\n");
	printf("8printf:\t.%015.7d.\n", 42);
	ft_printf("8ft_printf:\t.%015.7d.\n", 42);
	printf("\n");
	printf("9printf:\t.%.d.\n", 0);
	ft_printf("9ft_printf:\t.%.d.\n", 0);
	printf("\n");
	printf("10printf:\t.%2.d.\n", 0);
	ft_printf("10ft_printf:\t.%2.d.\n", 0);
	printf("\n");
	printf("11printf:\t.%.2d.\n", 0);
	ft_printf("11ft_printf:\t.%.2d.\n", 0);
	printf("\n");
	printf("12printf:\t.%08.3d.\n", 456);
	ft_printf("12ft_printf:\t.%08.3d.\n", 456);
	printf("\n");
	printf("13printf:\t.%08.2d.\n", 456);
	ft_printf("13ft_printf:\t.%08.2d.\n", 456);
	printf("\n");
	printf("14printf:\t.%08.5d.\n", 456);
	ft_printf("14ft_printf:\t.%08.5d.\n", 456);
	printf("\n");
	printf("15printf:\t.%03d.\n", -456);
	ft_printf("15ft_printf:\t.%03d.\n", -456);
	printf("\n");
}

void	test_u(void)
{
	printf("3printf:\t.%05u.\n", 42);
	ft_printf("3ft_printf:\t.%05u.\n", 42);
	printf("\n");
	printf("4printf:\t.%-8u.\n", -42);
	ft_printf("4ft_printf:\t.%-8u.\n", -42);
	printf("\n");
	printf("5printf:\t.%.u.\n", 42);
	ft_printf("5ft_printf:\t.%.u.\n", 42);
	printf("\n");
	printf("6printf:\t.%2.5u.\n", -42);
	ft_printf("6ft_printf:\t.%2.5u.\n", -42);
	printf("\n");
	printf("7printf:\t.%015u.\n", -42);
	ft_printf("7ft_printf:\t.%015u.\n", -42);
	printf("\n");
	printf("8printf:\t.%015.7u.\n", 42);
	ft_printf("8ft_printf:\t.%015.7u.\n", 42);
	printf("\n");
	printf("9printf:\t.%.u.\n", 0);
	ft_printf("9ft_printf:\t.%.u.\n", 0);
	printf("\n");
	printf("10printf:\t.%2.u.\n", 0);
	ft_printf("10ft_printf:\t.%2.u.\n", 0);
	printf("\n");
	printf("11printf:\t.%.2u.\n", 0);
	ft_printf("11ft_printf:\t.%.2u.\n", 0);
	printf("\n");
	printf("12printf:\t.%08.3u.\n", 456);
	ft_printf("12ft_printf:\t.%08.3u.\n", 456);
	printf("\n");
	printf("13printf:\t.%08.2u.\n", 456);
	ft_printf("13ft_printf:\t.%08.2u.\n", 456);
	printf("\n");
	printf("14printf:\t.%08.5u.\n", 456);
	ft_printf("14ft_printf:\t.%08.5u.\n", 456);
	printf("\n");
	printf("15printf:\t.%03u.\n", -456);
	ft_printf("15ft_printf:\t.%03u.\n", -456);
	printf("\n");
}

void	test_int(void)
{
	int inteiro;
//	int i = 42;

//	printf("%d %0d %-d %.2d\n", i, i ,i, i);
//	printf(". %-10d .\n", i);
//    printf(". %00010d .\n", i);
//    printf(". %- 10d .\n", i);
//    printf(". % -10d .\n", i);
	inteiro = 44;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	inteiro = -44;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	inteiro = 490904;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
	inteiro = -490904;
	printf("%%d=%d, %%i=%i, %%o=%o, %%u=%u, %%x=%x, %%X=%X\n", inteiro, inteiro, inteiro, inteiro, inteiro, inteiro);
}

void	test_float(void)
{
	float decimal;

	decimal = 44.65;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%.f, %%.0f=%.0f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = -44.65;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = 490904.656565;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
	decimal = -490904.656565;
	printf("%%f=%f, %%F=%F, %%.1f=%.1f, %%.f=%f, %%e=%e, %%.2e=%.2e\n", decimal, decimal, decimal, decimal, decimal, decimal);
}

int	main(void)
{
//	test_c();
	test_s();
//	test_p();
//	test_pct();
//	test_d();
//	test_u();
	return (0);
}
