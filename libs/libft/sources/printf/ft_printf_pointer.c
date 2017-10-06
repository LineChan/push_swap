/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:56:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling p, #x , #X types
*/

void			ft_printf_putnbr_p(unsigned long long p, t_struct *arg)
{
	if (p < 16)
		*arg->p++ = (arg->type == 'X' ? UP : LOW)[p % 16];
	else
	{
		ft_printf_putnbr_p(p / 16, arg);
		*arg->p++ = (arg->type == 'X' ? UP : LOW)[p % 16];
	}
}

static void		ft_printf_p_padd(t_struct *arg,
										int len,
										unsigned long long p)
{
	if (ZERO && !DOT)
		return ;
	else if (DOT)
	{
		if (!p)
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

static void		ft_printf_set_buff_p(t_struct *arg,
											int len,
											unsigned long long p)
{
	if (arg->dot < len)
		arg->dot ^= arg->dot;
	if (arg->padd && !MINUS)
		ft_printf_p_padd(arg, len, p);
}

static void		ft_printf_set_buff_p_after(t_struct *arg, int len, int p)
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
		if (!p)
			len ^= len;
		while ((arg->dot-- - len) > 0)
		{
			*arg->p++ = '0';
			arg->padd--;
			SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
		}
	}
}

void			ft_printf_pointer(t_struct *arg)
{
	unsigned long long			p;
	int							len;

	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	p = (ULL)va_arg(arg->ap, void *);
	if (!p && (arg->type == 'x' || arg->type == 'X'))
	{
		ft_printf_hexa_zero(arg);
		return ;
	}
	len = ft_uintlen(p, 16);
	ft_printf_set_buff_p(arg, len, p);
	*arg->p++ = '0';
	*arg->p++ = arg->type == 'X' ? 'X' : 'x';
	ft_printf_set_buff_p_after(arg, len, p);
	(p || !DOT) ? ft_printf_putnbr_p(p, arg) : 0;
	while ((arg->padd-- - len - 2) > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len - 2) ? 0 : ft_printf_write_buff(arg);
	}
}
