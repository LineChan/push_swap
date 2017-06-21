/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:29:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling '%' type and random char
*/

void			ft_printf_modulo(t_struct *arg)
{
	char	padd;

	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	padd = ZERO && !MINUS ? '0' : ' ';
	if (MINUS)
		*arg->p++ = arg->rdm ? arg->rdm : '%';
	if (arg->padd)
		while (--arg->padd)
		{
			*arg->p++ = padd;
			SIZE ^ (BUFF_MAX - 1) ? 0 : ft_printf_write_buff(arg);
		}
	if (!MINUS)
		*arg->p++ = arg->rdm ? arg->rdm : '%';
}
