/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 09:03:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#define LLM "9223372036854775808"

/*
** Handling i, d, D types
*/

static void			ft_printf_putnbr(long long nb, t_struct *arg)
{
	int		n;

	if (nb == LLONG_MIN)
	{
		n = 0;
		while (n < 19)
			*arg->p++ = LLM[n++];
		return ;
	}
	if (nb < 10)
		*arg->p++ = nb % 10 + '0';
	else
	{
		ft_printf_putnbr(nb / 10, arg);
		*arg->p++ = nb % 10 + '0';
	}
}

static void			ft_printf_int_flag_padd(t_struct *arg,
													int *len,
													int sign)
{
	char	padd;

	if (ZERO)
	{
		if ((PLUS || arg->neg) && sign-- && *len)
		{
			*arg->p++ = arg->neg ? '-' : '+';
			arg->padd--;
		}
		else if (SPACE && arg->padd--)
		{
			*arg->p++ = ' ';
			SIZE ^ (BUFF_MAX - *len - sign) ? 0 : ft_printf_write_buff(arg);
		}
	}
	if (arg->neg)
		(*len)--;
	padd = ZERO ? '0' : ' ';
	while ((arg->padd-- - sign - *len - arg->neg) > 0)
	{
		*arg->p++ = padd;
		SIZE ^ (BUFF_MAX - *len - sign) ? 0 : ft_printf_write_buff(arg);
	}
	if (sign)
		*arg->p++ = arg->neg ? '-' : '+';
}

static void			ft_printf_set_buff_int(t_struct *arg, int *len, int sign)
{
	if (DOT && arg->dot)
	{
		if (!(!arg->dot && !arg->padd))
			arg->dot = MAX(arg->dot, *len);
		if (arg->padd > arg->dot && !MINUS)
			while (arg->padd-- - sign - arg->dot)
			{
				*arg->p++ = ' ';
				SIZE ^ (BUFF_MAX - *len - sign) ? 0 : ft_printf_write_buff(arg);
			}
		if (sign)
			*arg->p++ = arg->neg ? '-' : '+';
		while ((arg->dot-- - *len) > 0)
		{
			*arg->p++ = '0';
			arg->padd--;
			SIZE ^ (BUFF_MAX - *len - sign) ? 0 : ft_printf_write_buff(arg);
		}
	}
	else if (arg->padd && !MINUS)
		ft_printf_int_flag_padd(arg, len, sign);
	else if (sign)
		*arg->p++ = arg->neg ? '-' : '+';
	else if (SPACE)
		*arg->p++ = ' ';
}

static void			ft_handle_undefined_case(t_struct *arg, int len, int sign)
{
	if (arg->padd)
		*arg->p++ = ' ';
	while ((arg->padd-- - len - sign) > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len - sign) ? 0 : ft_printf_write_buff(arg);
	}
}

void				ft_printf_int(t_struct *arg)
{
	int				len;
	int				sign;
	long long int	nb;

	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	if ((nb = ft_printf_convert_id(arg)) < 0)
	{
		arg->neg++;
		nb *= -1;
	}
	sign = (arg->neg || PLUS) ? 1 : 0;
	len = (nb == LLONG_MIN) ? 19 : ft_intlen(nb);
	if (!nb && !arg->dot && DOT)
	{
		ft_handle_undefined_case(arg, len, sign);
		return ;
	}
	ft_printf_set_buff_int(arg, &len, sign);
	ft_printf_putnbr(nb, arg);
	while ((arg->padd-- - len - sign) > 0)
	{
		*arg->p++ = ' ';
		SIZE ^ (BUFF_MAX - len) ? 0 : ft_printf_write_buff(arg);
	}
}
