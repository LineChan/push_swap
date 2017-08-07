/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:58:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/07/29 15:25:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Handling colors
*/
static char const		*g_save_colors[NB_COLORS_MAX + 1] = {0};

static char const		*g_colors_lst[] =
{
	"{RED:", "\033[31;1m",
	"{GREEN:", "\033[32;1m",
	"{YELLOW:", "\033[33;1m",
	"{BLUE:", "\033[34;1m",
	"{red:", "\033[31m",
	"{green:", "\033[32m",
	"{yellow:", "\033[33m",
	"{blue:", "\033[34m",
};

void					ft_printf_colors(char **s, t_struct *arg)
{
	size_t		size;
	size_t		len;

	NB_COLOR = 0;
	size = SIZEOF(g_colors_lst) - 2;
	g_save_colors[0] = "\033[0m";
	while ((int)size >= 0)
	{
		len = ft_strlen(g_colors_lst[size]);
		if (!ft_strncmp(g_colors_lst[size], *s, len))
		{
			NB_COLOR++ < NB_COLORS_MAX ? size++ : 0;
			g_save_colors[NB_COLOR] = g_colors_lst[size];
			SIZE ^ (BUFF_MAX + len) ? 0 : ft_printf_write_buff(arg);
			arg->p = ft_stpcpy(arg->p, g_save_colors[NB_COLOR]);
			*s += len - 1;
			*ret() -= ft_strlen(g_save_colors[NB_COLOR]) - 1;
			return ;
		}
		size -= 2;
	}
	*arg->p++ = **s++;
}

void					ft_printf_end_colors(char **s, t_struct *arg)
{
	if (NB_COLOR && *(*s - 1) != '\\')
	{
		g_save_colors[NB_COLOR--] = 0;
		arg->p = ft_stpcpy(arg->p, g_save_colors[NB_COLOR]);
		*ret() -= ft_strlen(g_save_colors[NB_COLOR]) + 1;
	}
	else
		*arg->p++ = **s++;
}
