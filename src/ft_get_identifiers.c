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
#include "libft.h"

void	get_flags(t_general *gen, t_ident *ident)
{
	gen->posit++;
	while (ft_strchr(FLAGS, gen->input[gen->posit]) && gen->input[gen->posit])
	{
		if (gen->input[gen->posit] == '-')
			ident->flags *= F_MINUS;
		else if (gen->input[gen->posit] == '+')
			ident->flags *= F_PLUS;
		else if (gen->input[gen->posit] == '0')
			ident->flags *= F_ZERO;
		else if (gen->input[gen->posit] == ' ')
			ident->flags *= F_SPACE;
		else if (gen->input[gen->posit] == '#')
			ident->flags *= F_HASH;
		gen->posit++;
	}
}

void	get_limits(t_general *gen, t_ident *ident)
{
	ident->width = get_sizes(gen, ident);
	if (gen->input[gen->posit] == '.')
	{
		gen->posit++;
		ident->precision = get_sizes(gen, ident);
	}
}

int		get_sizes(t_general *gen, t_ident *ident)
{
	int		size;

	size = 0;
	if (gen->input[gen->posit] == '*')
	{
		size = va_arg(gen->argument, int);
		gen->posit++;
		if (size < 0 && gen->input[gen->posit - 2] != '.')
		{
			ident->flags *= F_MINUS;
			size *= -1;
		}
	}
	else
	{
		size = ft_atoi(&gen->input[gen->posit]);
		while (ft_strchr(DIGITS, gen->input[gen->posit]) &&
				gen->input[gen->posit])
			gen->posit++;
	}
	return (size);
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
		else if (ident->conversion == '%')
			ft_printf_pct(gen, *ident);
		else if (ident->conversion == 'd' || ident->conversion == 'i' ||
					ident->conversion == 'x' || ident->conversion == 'X')
			ft_printf_d(gen, *ident);
		else if (ident->conversion == 'u')
			ft_printf_u(gen, *ident);
	}
	else
		ident->error = 1;
}
