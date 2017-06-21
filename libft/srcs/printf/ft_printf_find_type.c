/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_find_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 08:54:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Function applied according to the type found
*/

static const		t_printf g_printf[] =
{
	{'s', &ft_printf_string},
	{'S', &ft_printf_string},
	{'p', &ft_printf_pointer},
	{'d', &ft_printf_int},
	{'D', &ft_printf_int},
	{'i', &ft_printf_int},
	{'o', &ft_printf_octal},
	{'O', &ft_printf_octal},
	{'u', &ft_printf_unsigned},
	{'U', &ft_printf_unsigned},
	{'x', &ft_printf_hexa},
	{'X', &ft_printf_hexa},
	{'c', &ft_printf_string},
	{'C', &ft_printf_string},
	{'b', &ft_printf_binary},
	{'B', &ft_printf_binary},
	{'%', &ft_printf_modulo},
	{0, 0}
};

void				ft_printf_find_type(char c, t_struct *arg)
{
	int i;

	i = -1;
	if (!c)
		return ;
	while (g_printf[i++].c)
		if (g_printf[i].c == c)
		{
			arg->type = c;
			g_printf[i].func(arg);
			break ;
		}
}
