/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 01:46:02 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/31 01:46:09 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flags(t_general *gen, t_ident *ident)
{
	gen->posit++;
	while (ft_strchr(FLAGS, gen->input[gen->posit]))
	{
		if (gen->input[gen->posit] == '-')
			ident->flags *= FLAG_MINUS;
		else if (gen->input[gen->posit] == '+')
			ident->flags *= FLAG_PLUS;
		else if (gen->input[gen->posit] == '0')
			ident->flags *= FLAG_ZERO;
		else if (gen->input[gen->posit] == ' ')
			ident->flags *= FLAG_SPACE;
		else if (gen->input[gen->posit] == '#')
			ident->flags *= FLAG_HASH;
		gen->posit++;
	}
}

int		get_sizes(t_general *gen)
{
	int		size;

	size = 0;
	if (gen->input[gen->posit] == '*')
	{
		size = va_arg(gen->argument, int);
		gen->posit++;
	}
	else
	{
		size = ft_atoi(&gen->input[gen->posit]);
		while (ft_strchr(DIGITS, gen->input[gen->posit]))
			gen->posit++;
	}
	return (size);
}

void	get_limits(t_general *gen, t_ident *ident)
{
	ident->width = get_sizes(gen);
	if (gen->input[gen->posit] == '.')
	{
		gen->posit++;
		ident->precision = get_sizes(gen);
	}
}

void	get_conversion(t_general *gen, t_ident *ident)
{
	if (ft_strchr(CONVERSION, gen->input[gen->posit]))
	{
		ident->conversion = gen->input[gen->posit];
		gen->posit++;
		if (ident->conversion == 'c')
			ft_printf_c(gen, *ident);
		else if (ident->conversion == 's')
			ft_printf_s(gen, *ident);
		else if (ident->conversion == 'p')
			ft_printf_p(gen, *ident);
	}
	else
		ident->error = 1;
}
