/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:30:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling c, s types
*/

static void		ft_printf_c(t_struct *arg)
{
	char	padd;

	padd = ZERO ? '0' : ' ';
	while (!MINUS && --arg->padd > 0)
	{
		*arg->p++ = padd;
		SIZE ^ (BUFF_MAX - 1) ? 0 : ft_printf_write_buff(arg);
	}
	*arg->p++ = (unsigned int)(int)va_arg(arg->ap, int);
	while (MINUS && --arg->padd)
	{
		*arg->p++ = ' ';
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
	}
}

static void		ft_printf_set_buff_s(t_struct *arg, int *len, char *s)
{
	char	padd;
	int		s_len;

	s_len = (int)ft_strlen(s);
	if (DOT)
	{
		if (!arg->dot)
			*len ^= *len;
		else
			*len = arg->dot > s_len ? s_len : arg->dot;
	}
	else
		*len = s_len;
	padd = ZERO ? '0' : ' ';
	while (!MINUS && (arg->padd-- - *len) > 0)
	{
		*arg->p++ = padd;
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
	}
}

static void		ft_printf_s(t_struct *arg)
{
	char	*s;
	int		len;
	int		tmp;

	len = 0;
	if (!(s = (char *)va_arg(arg->ap, char *)))
		s = "(null)";
	ft_printf_set_buff_s(arg, &len, s);
	tmp = len;
	while (len--)
	{
		*arg->p++ = *s++;
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
	}
	while (MINUS && (arg->padd-- > tmp))
		*arg->p++ = ' ';
}

void			ft_printf_string(t_struct *arg)
{
	(WILD || WILD_D) ? ft_printf_wild(arg) : 0;
	if ((arg->type == 's') && !M_L)
		ft_printf_s(arg);
	else if ((arg->type == 'c') && !M_L)
		ft_printf_c(arg);
	else if ((M_L && arg->type == 'c') || arg->type == 'C')
		ft_printf_lc(arg, (wchar_t)va_arg(arg->ap, wchar_t));
	else
		ft_printf_ls(arg);
}
