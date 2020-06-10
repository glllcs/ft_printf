/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_charac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 01:50:36 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/31 01:50:38 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printf_c(t_general *gen, t_ident ident)
{
	int		c;
	char	pre[2];

	c = va_arg(gen->argument, int);
	pre[0] = (c) ? (unsigned char)c : '\0';
	pre[1] = '\0';
	ft_print_all(gen, ident, pre);
}

void			ft_printf_s(t_general *gen, t_ident ident)
{
	char	*str;

	if (!(str = ft_strdup(va_arg(gen->argument, char *))))
		str = ft_strdup("(null)");
	if (ident.precision == 0 && ident.width == 0)
	{
		ft_strfree(&str);
		return ;
	}
	if (ident.precision >= 0 && ident.precision < (int)ft_strlen(str))
		str[ident.precision] = '\0';
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void			ft_printf_p(t_general *gen, t_ident ident)
{
	size_t	p;
	char	*temp;
	char	*str;

	p = va_arg(gen->argument, size_t);
	temp = ft_itoa_base_u(p, B_HEX_L);
	if (ident.precision == 0 && p == 0)
		temp[ident.precision] = '\0';
	str = ft_strjoin("0x", temp);
	ft_strfree(&temp);
	ft_print_all(gen, ident, str);
	ft_strfree(&str);
}

void			ft_printf_pct(t_general *gen, t_ident ident)
{
	char	pre[2];

	pre[0] = '%';
	pre[1] = '\0';
	ft_print_all(gen, ident, pre);
}
