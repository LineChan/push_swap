/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:10:18 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling o, O types
*/

static void		ft_printf_putnbr_o(unsigned long long nb, t_struct *arg)
{
	if (nb < 8)
		*arg->p++ = nb % 8 + '0';
	else
	{
		ft_printf_putnbr_o(nb / 8, arg);
		*arg->p++ = nb % 8 + '0';
	}
}

static void		ft_printf_set_buff_octal(t_struct *arg, int len,
													unsigned long long nb)
{
	char				padd;
	int					sharp;

	sharp = (SHARP && nb) ? 1 : 0;
	len += sharp;
	arg->dot = MAX(arg->dot, len);
	if (!MINUS)
	{
		padd = (ZERO && !DOT) ? '0' : ' ';
		while ((arg->padd-- - arg->dot) > 0)
		{
			*arg->p++ = padd;
			SIZE ^ (BUFF_MAX - len - sharp) ? 0 : ft_printf_write_buff(arg);
		}
	}
	while ((arg->dot-- - len) > 0)
	{
		*arg->p++ = '0';
		arg->padd--;
		SIZE ^ (BUFF_MAX - len - sharp) ? 0 : ft_printf_write_buff(arg);
	}
	if (sharp)
		*arg->p++ = '0';
}

void			ft_printf_octal(t_struct *arg)
{
	unsigned long long	nb;
	int					len;

	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	nb = ft_printf_convert_unsigned(arg);
	len = ft_uintlen(nb, 8);
	ft_printf_set_buff_octal(arg, len, nb);
	if (!(!nb && DOT && !arg->dot && !SHARP))
		ft_printf_putnbr_o(nb, arg);
	else if (!arg->padd)
		*arg->p++ = ' ';
	SHARP ? len++ : 0;
	while ((arg->padd-- - len) > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
	}
}
