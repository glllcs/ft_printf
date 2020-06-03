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

void	ft_init_ident(t_ident *identifier)
{
	identifier->flags = 1;
	identifier->width = -1;
	identifier->precision = -1;
	identifier->conversion = 0;
	identifier->conversion = 0;
	identifier->error = 0;
}

/*
** Atributes the conversion, if it's in CONVERSION, to ident->conversion
** and increments i. If it isn't in CONVERSION, atributes 1 to ident->error
*/

void	print_ident(t_ident ident)
{
	ft_putchar_fd('[', 1);
	if (ident.flags % FLAG_HASH == 0)
		ft_putchar_fd('#', 1);
	if (ident.flags % FLAG_MINUS == 0)
		ft_putchar_fd('-', 1);
	if (ident.flags % FLAG_PLUS == 0)
		ft_putchar_fd('+', 1);
	if (ident.flags % FLAG_SPACE == 0)
		ft_putchar_fd(' ', 1);
	if (ident.flags % FLAG_ZERO == 0)
		ft_putchar_fd('0', 1);
	if (ident.width != -1)
		ft_putstr_fd(ft_itoa(ident.width), 1);
	if (ident.precision != -1)
	{
		ft_putchar_fd('.', 1);
		ft_putstr_fd(ft_itoa(ident.precision), 1);
	}
	ft_putchar_fd(ident.conversion, 1);
	ft_putchar_fd(']', 1);
}

/*void	ft_init_general(t_general *gen, const char *input)
{
	gen->posit = 0;
	gen->len = 0;
	gen->input = ft_strdup(input);
}*/

void	ft_print_ident(t_general *gen, t_ident *ident)
{
	get_flags(gen, ident);
	get_limits(gen, ident);
	get_conversion(gen, ident);
	//print_ident(*ident);
}

int		ft_printf(const char *input, ...)
{
	t_general	gen;
	t_ident		ident;

	gen.posit = 0;
	gen.size = 0;
	ft_init_ident(&ident);
	//ft_init_general(&gen, input);
	gen.input = ft_strdup(input);
	va_start(gen.argument, input);
	while (gen.input[gen.posit])
	{
		if (input[gen.posit] != '%')
		{
			ft_putchar_fd(gen.input[gen.posit], 1);
			gen.posit++;
			gen.size++;
		}
		else
		{
			ft_print_ident(&gen, &ident);
		}
	}
	va_end(gen.argument);
	//ft_putchar_fd('[', 1);
	//ft_putstr_fd(ft_itoa(gen.size), 1);
	//ft_putchar_fd(']', 1);
	return (gen.size);
}
