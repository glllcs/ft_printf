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

# define FLAG_MINUS	2
# define FLAG_PLUS	3
# define FLAG_ZERO	5
# define FLAG_SPACE	7
# define FLAG_HASH	11

typedef struct s_output
{
	const char	*input;
	char		*output;
	va_list		argument;
	int			size;
	int			posit;
}				t_output;

typedef struct s_ident
{
	int		flags;
	int		width;
	int		precision;
	char	conversion;
	char	*argument;
	int		error;
}			t_ident;

int		ft_printf(const char *phrase, ...);

#endif
