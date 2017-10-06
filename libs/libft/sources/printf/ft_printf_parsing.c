/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:48:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Parsing the string sent to printf
*/

static void		ft_printf_undefined(char **s, t_struct *arg)
{
	if (arg->flag)
		return ;
	while (!ft_isalpha(**s) || **s == ' ' || ft_strchr(TYPE, **s))
	{
		if (**s == '%')
		{
			ft_printf_write_buff(arg);
			break ;
		}
		(*s)--;
	}
	while (*++(*s))
		*arg->p++ = **s;
}

static void		ft_printf_find_options(char **s, t_struct *arg)
{
	while (!ft_strchr(TYPE, *++(*s)))
	{
		if (ft_isalpha(**s) && !ft_strchr(MOD_LIST, **s))
		{
			arg->rdm = **s;
			ft_printf_analyse('c', arg);
			return ;
		}
		else
			ft_printf_analyse(**s, arg);
	}
}

void			ft_printf_parsing(char *s, t_struct *arg)
{
	NB_COLOR ^= NB_COLOR;
	while (*s)
	{
		if (*s == '%')
		{
			ft_printf_init_struct(arg);
			ft_printf_find_options(&s, arg);
			if (!(*s))
			{
				ft_printf_undefined(&s, arg);
				break ;
			}
			arg->rdm ? 0 : ft_printf_find_type(*s, arg);
		}
		else if (*s == '{')
			ft_printf_colors(&s, arg);
		else if (*s == '}')
			ft_printf_end_colors(&s, arg);
		else
			*arg->p++ = *s;
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
		s++;
	}
	*ret() += write(1, arg->buff, SIZE);
}
