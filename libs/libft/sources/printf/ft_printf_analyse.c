/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 00:41:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:06:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Each time a flag is found, the corresponding bit is activated
*/

static void		ft_printf_find_mods(char c, t_struct *arg)
{
	if (c == 'h')
		arg->flag |= M_H ? MOD_HH : MOD_H;
	else if (c == 'l')
		arg->flag |= M_L ? MOD_LL : MOD_L;
	else if (c == 'j')
		arg->flag |= MOD_J;
	else if (c == 'z')
		arg->flag |= MOD_Z;
}

static void		ft_printf_find_flags(char c, t_struct *arg)
{
	if (c == '-')
		arg->flag |= FLAG_MINUS;
	else if (c == '+')
		arg->flag |= FLAG_PLUS;
	else if (c == '0' && !DOT && !arg->padd)
		arg->flag |= FLAG_ZERO;
	else if (c == ' ')
		arg->flag |= FLAG_SPACE;
	else if (c == '.')
		arg->flag |= FLAG_DOT;
	else if (!DOT && ft_isdigit(c))
		arg->padd = arg->padd * 10 + c - 48;
	else if (DOT && ft_isdigit(c))
		arg->dot = arg->dot * 10 + c - 48;
	else if (c == '#')
		arg->flag |= FLAG_SHARP;
	else if (c == '*' && !DOT)
	{
		arg->flag |= FLAG_WILD;
		if (arg->padd)
			arg->padd ^= arg->padd;
	}
	else if (c == '*')
		arg->flag |= FLAG_WILD_DOT;
}

void			ft_printf_analyse(char c, t_struct *arg)
{
	if (ft_isalpha(c))
	{
		if (ft_strchr(MOD_LIST, c))
			ft_printf_find_mods(c, arg);
		else
			ft_printf_modulo(arg);
	}
	else
		ft_printf_find_flags(c, arg);
}
