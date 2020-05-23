/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 13:52:39 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/23 19:54:24 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(int c)
{
	ft_putchar_fd(c, 1);
}

void	ft_printf_s(char *s)
{
	ft_putstr_fd(s, 1);
}

int	ft_printf(const char *phrase, ...)
{
	int	i;
	va_list	argm;

	i = 0;
	va_start(argm, phrase);
	while (phrase[i])
	{
		if (phrase[i] != '%')
			ft_putchar_fd(phrase[i], 1);
		else if (phrase[i + 1] == 'c')
		{
			ft_printf_c(va_arg(argm, int));
			i++;
		}
		else if (phrase[i + 1] == 's')
		{
			ft_printf_s(va_arg(argm, char *));
			i++;
		}
		i++;
	}
	va_end(argm);
	return (i);
}
