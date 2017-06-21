/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 01:31:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling x, X types
** (SHARP flag case converted to p type)
*/

void				ft_printf_hexa_zero(t_struct *arg)
{
	int		zero;
	char	padd;

	padd = ZERO && !DOT ? '0' : ' ';
	zero = !DOT ? 1 : 0;
	while (arg->padd-- - arg->dot - zero > 0)
	{
		*arg->p++ = padd;
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
	}
	if (zero)
		*arg->p++ = '0';
	while (arg->dot--)
	{
		*arg->p++ = '0';
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
	}
}

static void			ft_printf_set_buff_hexa(t_struct *arg, int len)
{
	char	padd;

	arg->dot = MAX(arg->dot, len);
	if (!MINUS)
	{
		padd = ZERO && !DOT ? '0' : ' ';
		while (arg->padd-- - arg->dot > 0)
		{
			*arg->p++ = padd;
			SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
		}
	}
	while (arg->dot-- - len > 0)
	{
		*arg->p++ = '0';
		arg->padd--;
		SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
	}
}

void				ft_printf_hexa(t_struct *arg)
{
	unsigned long long	nb;
	int					len;

	arg->padd = WILD ? va_arg(arg->ap, int) : arg->padd;
	if (SHARP)
	{
		ft_printf_pointer(arg);
		return ;
	}
	nb = ft_printf_convert_unsigned(arg);
	len = ft_uintlen(nb, 16);
	if (!nb)
	{
		ft_printf_hexa_zero(arg);
		return ;
	}
	ft_printf_set_buff_hexa(arg, len);
	ft_printf_putnbr_p(nb, arg);
	while (arg->padd-- - len > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
	}
}
