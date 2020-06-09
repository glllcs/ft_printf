/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 09:45:32 by lambrozi          #+#    #+#             */
/*   Updated: 2020/05/23 19:02:40 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define CONVERSION	"cspdiuxX%"

# define FLAGS		"-+0 #"
# define DIGITS		"0123456789"

# define F_MINUS	2
# define F_PLUS		3
# define F_ZERO		5
# define F_SPACE	7
# define F_HASH		11

# define B_DEC	"0123456789"
# define B_HEX	"0123456789abcdef"

typedef struct	s_general
{
	const char	*input;
	char		*output;
	va_list		argument;
	int			size;
	int			posit;
}				t_general;

typedef struct	s_ident
{
	int		flags;
	int		width;
	int		precision;
	char	conversion;
	char	*argument;
	char	*pre_output;
	int		error;
}				t_ident;

int				ft_printf(const char *phrase, ...);
void			ft_init_ident(t_ident *identifier);
void			get_flags(t_general *gen, t_ident *ident);
int				get_sizes(t_general *gen);
void			get_limits(t_general *gen, t_ident *ident);
void			get_conversion(t_general *gen, t_ident *ident);
int				ft_print_space(int cont, t_ident ident);
void			ft_printf_c(t_general *gen, t_ident ident);
void			ft_printf_s(t_general *gen, t_ident ident);
void			ft_printf_p(t_general *gen, t_ident ident);
void			ft_printf_d(t_general *gen, t_ident ident);
void			ft_printf_u(t_general *gen, t_ident ident);
void			ft_printf_pct(t_general *gen, t_ident ident);
void			ft_strfree(char **str);
void			ft_print_all(t_general *gen, t_ident ident, char *pre);

#endif
