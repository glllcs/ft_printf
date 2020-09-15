/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_identifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:16:04 by lambrozi          #+#    #+#             */
/*   Updated: 2020/09/03 10:16:16 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** While there's a flag in the convertion, saves it in ident->flags
*/

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

/*
** Gets both width and precision to the convertion and save them, with the
** help of the function get_sizes, at ident->width and ident->precision,
** respectively
*/

void	get_limits(t_general *gen, t_ident *ident)
{
	ident->width = get_sizes(gen, ident);
	if (gen->input[gen->posit] == '.')
	{
		gen->posit++;
		ident->precision = get_sizes(gen, ident);
	}
}

/*
** If the character correspondent to the size is an *, gets the argument.
** If the number is already written, transforms it in a string via ft_atoi.
** Returns the number correspont to the width or the precision.
*/

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

/*
** Atributes the conversion, if it's in CONVERSION, to ident->conversion.
** Calls the correspondent function depending on the convertion.
** If it isn't in CONVERSION, atributes 1 to ident->error
*/

void	get_conversion(t_general *gen, t_ident *ident)
{
	if (ft_strchr(CONVERSION, gen->input[gen->posit]))
	{
		ident->conversion = gen->input[gen->posit];
		gen->posit++;
		if (ident->conversion == 'c')
			ft_prepare_c(gen, *ident);
		else if (ident->conversion == 's')
			ft_prepare_s(gen, *ident);
		else if (ident->conversion == 'p')
			ft_prepare_p(gen, *ident);
		else if (ident->conversion == '%')
			ft_prepare_pct(gen, *ident);
		else
			ft_prepare_nbr(gen, *ident);
	}
	else
		ident->error = 1;
}
