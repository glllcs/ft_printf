/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 08:44:34 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/04 08:44:37 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialize struct t_ident
*/

void	ft_init_ident(t_ident *identifier)
{
	identifier->flags = 1;
	identifier->width = -1;
	identifier->precision = -1;
	identifier->conversion = 0;
	identifier->error = 0;
}

/*
** For every identifier in ft_printf's call, initializes the ident's struct,
** get its flags, widths, precisions and, finaly, its convertion
*/

void	ft_print_ident(t_general *gen, t_ident *ident)
{
	ft_init_ident(ident);
	get_flags(gen, ident);
	get_limits(gen, ident);
	get_conversion(gen, ident);
}

/*
** Main function: goes through every char in the input and prints the literal
** characteres or calls ft_print_ident when the char is a %.
** Returns the total size of the printed string.
*/

int		ft_printf(const char *input, ...)
{
	t_general	gen;
	t_ident		ident;

	gen.posit = 0;
	gen.size = 0;
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
	return (gen.size);
}
