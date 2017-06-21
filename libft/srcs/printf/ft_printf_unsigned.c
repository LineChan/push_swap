/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:39:04 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling u, U types
*/

static void			ft_printf_putnbr_u(unsigned long long nb, t_struct *arg)
{
	if (nb < 10)
		*arg->p++ = nb % 10 + '0';
	else
	{
		ft_printf_putnbr_u(nb / 10, arg);
		*arg->p++ = nb % 10 + '0';
	}
}

static void			ft_printf_set_buff_unsigned(t_struct *arg, int len)
{
	char				padd;

	arg->dot = MAX(arg->dot, len);
	if (!MINUS)
	{
		padd = (ZERO && !DOT) ? '0' : ' ';
		while ((arg->padd-- - arg->dot) > 0)
		{
			*arg->p++ = padd;
			SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
		}
	}
	while ((arg->dot-- - len) > 0)
	{
		*arg->p++ = '0';
		arg->padd--;
		SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
	}
}

void				ft_printf_unsigned(t_struct *arg)
{
	unsigned long long	nb;
	int					len;

	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	nb = ft_printf_convert_unsigned(arg);
	len = ft_uintlen(nb, 10);
	ft_printf_set_buff_unsigned(arg, len);
	(nb || !DOT) ? ft_printf_putnbr_u(nb, arg) : 0;
	while ((arg->padd-- - len) > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
	}
}
