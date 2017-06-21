/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:46:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling * case
*/

void			ft_printf_wild(t_struct *arg)
{
	int		wild;

	if (WILD)
	{
		wild = va_arg(arg->ap, int);
		arg->flag |= wild < 0 ? FLAG_MINUS : arg->flag;
		if (!arg->padd)
			arg->padd = wild ? ABS(wild) : arg->padd;
	}
	if (WILD_D)
	{
		if (ZERO)
		{
			arg->dot = arg->padd;
			wild = va_arg(arg->ap, int);
		}
		else
			arg->dot = va_arg(arg->ap, int);
	}
	if (arg->dot < 0 && (arg->type == 's' || arg->type == 'S'))
		arg->flag &= ~FLAG_DOT;
}
