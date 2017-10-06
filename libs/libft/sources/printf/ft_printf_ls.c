/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 09:13:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling ls, S types
*/

static int				ft_printf_adapt_dot(wchar_t *ws, t_struct *arg)
{
	int		prec;

	prec = 0;
	while (*ws)
	{
		prec += ft_wclen(*ws++);
		if (prec + ft_wclen(*ws) > arg->dot)
			break ;
	}
	return (prec);
}

static void				ft_printf_set_buff_ls(t_struct *arg,
												int *len,
												wchar_t *ws)
{
	char	padd;
	int		wslen;

	wslen = ft_wstrlen(ws);
	if (DOT)
	{
		if (!arg->dot)
			*len ^= *len;
		else
			*len = arg->dot > wslen ? wslen : ft_printf_adapt_dot(ws, arg);
	}
	else
		*len = wslen;
	padd = ZERO ? '0' : ' ';
	if (!MINUS)
		while (arg->padd-- > *len)
		{
			*arg->p++ = padd;
			SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
		}
}

void					ft_printf_ls(t_struct *arg)
{
	wchar_t		*ws;
	int			len;
	int			tmp;

	if (!(ws = (wchar_t *)va_arg(arg->ap, wchar_t *)))
		ws = L"(null)";
	ft_printf_set_buff_ls(arg, &len, ws);
	tmp = len;
	while (len)
	{
		len -= ft_printf_unicode_string(arg, *ws++);
		SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
		if (len < ft_wclen(*ws))
			break ;
	}
	if (MINUS)
		while (arg->padd-- > tmp)
		{
			*arg->p++ = ' ';
			SIZE ^ BUFF_MAX ? 0 : ft_printf_write_buff(arg);
		}
}
