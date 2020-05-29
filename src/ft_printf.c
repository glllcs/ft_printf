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

void	ft_printf_c(t_general *gen, t_ident ident)
{
	char	*temp;
	int		c;
	int		i;

	c = va_arg(gen->argument, int);
	if(!(temp = (char *)ft_calloc(ident.width + 1, sizeof(char))))
		return ;
	ft_memset(temp, ' ', ident.width);
	temp[ident.width] = '\0';
	i = 0;
	if (ident.flags % FLAG_MINUS == 0)
		temp[i] = c;
	else
		temp[ident.width - 1] = c;
	ft_putstr_fd(temp, 1);
	free(temp);
}

/*
 * Atributes the conversion, if it's in CONVERSION, to ident->conversion and increments i
 * If it isn't in CONVERSION, atributes 1 to ident->error
*/

void	get_conversion(t_general *gen, t_ident *ident)
{
	if (ft_strchr(CONVERSION, gen->input[gen->posit]))
	{
		ident->conversion = gen->input[gen->posit];
		gen->posit++;
		if (ident->conversion == 'c')
			ft_printf_c(gen, *ident);
		/*else if (ident->conversion == 's')
			ft_printf_s(gen, *ident);*/
	}
	else
		ident->error = 1;
}

/*void	ft_printf_s(t_general *gen, t_ident ident)
{
	char	*temp;
	char	*str;
	size_t	i;
	size_t	str_len;

	str = va_arg(gen->argument, char *);
	str_len = (ident.width )
	if (!(str = (char *)ft_calloc()))
	ft_putstr_fd(s, 1);
}*/

void	ft_printf_d(int c)
{
	ft_putnbr_fd(c, 1);
}

void	print_ident(t_ident ident)
{
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
	ft_putchar_fd('\n', 1);
}

/*void	ft_init_general(t_general *gen, const char *input)
{
	gen->posit = 0;
	gen->input = ft_strdup(input);
	va_start(gen->argument, input);
}*/

void	ft_print_ident(t_general *gen, t_ident *ident)
{
	get_flags(gen, ident);
	get_limits(gen, ident);
	get_conversion(gen, ident);
	print_ident(*ident);
}

int	ft_printf(const char *input, ...)
{
	t_general	gen;
	t_ident		ident;

	gen.posit = 0;
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
		}
		else
		{
			ft_print_ident(&gen, &ident);

		}
	}
	va_end(gen.argument);
	return (gen.posit);
}
