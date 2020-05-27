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
    identifier->width = 0;
    identifier->precision = 0;
    identifier->conversion = 0;
    identifier->conversion = 0;
    identifier->error = 0;
}

void	get_flags(int *i, const char *phrase, t_ident *ident)
{
	(*i)++;
	while (ft_strchr(FLAGS, phrase[*i]))
	{
		if (phrase[*i] == '-')
			ident->flags *= FLAG_MINUS;
		else if (phrase[*i] == '+')
			ident->flags *= FLAG_PLUS;
		else if (phrase[*i] == '0')
			ident->flags *= FLAG_ZERO;
		else if (phrase[*i] == ' ')
			ident->flags *= FLAG_SPACE;
		else if (phrase[*i] == '#')
			ident->flags *= FLAG_HASH;
		else if (phrase[*i] == '*')
			ident->flags *= FLAG_ASTER;
		(*i)++;
	}
}

void	get_limits(int *i, const char *phrase, t_ident *ident)
{
	ident->width = ft_atoi(&phrase[*i]);
	while (ft_strchr(DIGITS, phrase[*i]))
		(*i)++;	
	if (phrase[*i] == '.')
		(*i)++;
	ident->precision = ft_atoi(&phrase[*i]);
	while (ft_strchr(DIGITS, phrase[*i]))
		(*i)++;		
}

/*
 * Atributes the conversion, if it's in CONVERSION, to ident->conversion and increments i
 * If it isn't in CONVERSION, atributes 1 to ident->error
*/

void	get_conversion(int *i, const char *phrase, t_ident *ident)
{
	if (ft_strchr(CONVERSION, phrase[*i]))
	{
		ident->conversion = phrase[*i];
		(*i)++;
	}
	else
		ident->error = 1;
}

void	ft_printf_c(int c)
{
	ft_putchar_fd(c, 1);
}

void	ft_printf_s(char *s)
{
	ft_putstr_fd(s, 1);
}

void	ft_printf_d(int c)
{
	ft_putnbr_fd(c, 1);
}

int	ft_printf(const char *phrase, ...)
{
	int		i;
	va_list	argm;
	t_ident	ident;

	i = 0;
	ft_init_ident(&ident);
	va_start(argm, phrase);
	while (phrase[i])
	{
		if (phrase[i] != '%')
			ft_putchar_fd(phrase[i], 1);
		else
		{
			get_flags(&i, phrase, &ident);
			get_limits(&i, phrase, &ident);
			get_conversion(&i, phrase, &ident);
			ft_putstr_fd("[flags:", 1);
			ft_putnbr_fd(ident.flags, 1);
			ft_putstr_fd("][width:", 1);
			ft_putnbr_fd(ident.width, 1);
			ft_putstr_fd("][precision:", 1);
			ft_putnbr_fd(ident.precision, 1);
			ft_putstr_fd("][conversion:", 1);
			ft_putchar_fd(ident.conversion, 1);
			ft_putstr_fd("][error:", 1);
			ft_putnbr_fd(ident.error, 1);
			ft_putstr_fd("]", 1);
		}
		
		i++;
	}
	va_end(argm);
	return (i);
}
