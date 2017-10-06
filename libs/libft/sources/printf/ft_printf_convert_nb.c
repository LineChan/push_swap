/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_nb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:51:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Converting numbers according to the modifier found (MOD)
*/

long long int				ft_printf_convert_id(t_struct *arg)
{
	if (arg->type == 'D')
		return ((LL)va_arg(arg->ap, long int));
	if (M_Z)
		return ((LL)(size_t)va_arg(arg->ap, size_t));
	if (M_J)
		return ((LL)(uintmax_t)va_arg(arg->ap, LL));
	if (M_LL)
		return ((LL)va_arg(arg->ap, LL));
	if (M_L)
		return ((LL)(long)va_arg(arg->ap, long));
	if (M_HH)
		return ((LL)(signed char)va_arg(arg->ap, int));
	if (M_H)
		return ((LL)(short)va_arg(arg->ap, int));
	return ((LL)(int)va_arg(arg->ap, int));
}

unsigned long long			ft_printf_convert_unsigned(t_struct *arg)
{
	if (arg->type == 'O' || arg->type == 'U')
		return ((ULL)va_arg(arg->ap, long int));
	if (M_HH)
		return ((ULL)(unsigned char)va_arg(arg->ap, unsigned int));
	if (M_H)
		return ((ULL)(unsigned short)va_arg(arg->ap, unsigned int));
	if (M_LL)
		return ((ULL)va_arg(arg->ap, ULL));
	if (M_L)
		return ((ULL)(unsigned long)va_arg(arg->ap, unsigned long));
	if (M_J)
		return ((ULL)(uintmax_t)va_arg(arg->ap, ULL));
	if (M_Z)
		return ((ULL)(size_t)va_arg(arg->ap, size_t));
	return ((ULL)va_arg(arg->ap, unsigned int));
}
