/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:07:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling b, B types
*/

void				ft_printf_putnbr_b(unsigned long long nb, t_struct *arg)
{
	if (nb < 2)
		*arg->p++ = (nb & 1) + '0';
	else
	{
		ft_printf_putnbr_b(nb / 2, arg);
		*arg->p++ = (nb & 1) + '0';
	}
}

static void			ft_printf_b_padd(t_struct *arg,
												int len,
												unsigned long long nb)
{
	if (ZERO && !DOT)
		return ;
	else if (DOT)
	{
		if (!nb)
			len ^= len;
		if (!arg->dot)
			while ((arg->padd-- - arg->dot - len - 2) > 0)
			{
				*arg->p++ = ' ';
				SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
			}
		else
			while ((arg->padd-- - arg->dot - 2) > 0)
			{
				*arg->p++ = ' ';
				SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
			}
	}
	else
		while ((arg->padd-- - len - 2) > 0)
		{
			*arg->p++ = ' ';
			SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
		}
}

static void			ft_printf_set_buff_b(t_struct *arg,
												int len,
												unsigned long long nb)
{
	if (arg->dot < len)
		arg->dot ^= arg->dot;
	if (arg->padd && !MINUS)
		ft_printf_b_padd(arg, len, nb);
}

static void			ft_printf_set_buff_b_after(t_struct *arg,
												int len,
												unsigned long long nb)
{
	if (ZERO && !MINUS)
		while ((arg->padd-- - len - 2) > 0)
		{
			*arg->p++ = '0';
			arg->dot--;
			SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
		}
	if (DOT && arg->dot)
	{
		if (!nb)
			len ^= len;
		while ((arg->dot-- - len) > 0)
		{
			*arg->p++ = '0';
			arg->padd--;
			SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
		}
	}
}

void				ft_printf_binary(t_struct *arg)
{
	unsigned long long			nb;
	int							len;

	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	nb = ft_printf_convert_unsigned(arg);
	len = ft_uintlen(nb, 2);
	ft_printf_set_buff_b(arg, len, nb);
	*arg->p++ = '0';
	*arg->p++ = arg->type == 'B' ? 'B' : 'b';
	nb || !DOT ? ft_printf_putnbr_b(nb, arg) : 0;
	ft_printf_set_buff_b_after(arg, len, nb);
	while ((arg->padd-- - len - 2) > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
	}
}
