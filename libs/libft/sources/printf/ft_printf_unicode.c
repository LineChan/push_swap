/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:31:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Convert UNICODES
**
** Binariy masks :
** 00000000 -- 0000007F: 	0xxxxxxx
** 00000080 -- 000007FF: 	110xxxxx 10xxxxxx
** 00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
** 00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

void			ft_printf_lc(t_struct *arg, wchar_t wc)
{
	if (wc < 0x80)
		*arg->p++ = (char)wc;
	else if (wc < 0x800)
	{
		*arg->p++ = ((wc >> 6) & 0x1f) | 0xc0;
		*arg->p++ = (wc & 0x3f) | 0x80;
	}
	else if (wc < 0x10000)
	{
		*arg->p++ = (wc >> 12 & 0x1f) | 0xe0;
		*arg->p++ = (wc >> 6 & 0x3f) | 0x80;
		*arg->p++ = (wc & 0x3f) | 0x80;
	}
	else if (wc < 0x110000)
	{
		*arg->p++ = (wc >> 18 & 0x7) | 0xf0;
		*arg->p++ = (wc >> 12 & 0x3f) | 0x80;
		*arg->p++ = (wc >> 6 & 0x3f) | 0x80;
		*arg->p++ = (wc & 0x3f) | 0x80;
	}
}

static void		ft_norme(t_struct *arg, wchar_t wc)
{
	*arg->p++ = (wc >> 18 & 0x7) | 0xf0;
	*arg->p++ = (wc >> 12 & 0x3f) | 0x80;
	*arg->p++ = (wc >> 6 & 0x3f) | 0x80;
	*arg->p++ = (wc & 0x3f) | 0x80;
}

int				ft_printf_unicode_string(t_struct *arg, wchar_t wc)
{
	if (wc < 0x80)
	{
		*arg->p++ = (char)wc;
		return (1);
	}
	else if (wc < 0x800)
	{
		*arg->p++ = ((wc >> 6) & 0x1f) | 0xc0;
		*arg->p++ = (wc & 0x3f) | 0x80;
		return (2);
	}
	else if (wc < 0x10000)
	{
		*arg->p++ = (wc >> 12 & 0x1f) | 0xe0;
		*arg->p++ = (wc >> 6 & 0x3f) | 0x80;
		*arg->p++ = (wc & 0x3f) | 0x80;
		return (3);
	}
	else if (wc < 0x110000)
	{
		ft_norme(arg, wc);
		return (4);
	}
	return (0);
}
