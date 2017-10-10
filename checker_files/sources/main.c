/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:49:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/10 20:26:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Check the result given by push_swap
*/

int				main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	++av;
	--ac;
	if (!ft_strcmp("-x", *av))
	{
		CURSE_MODE = 1;
		++av;
		--ac;
	}
	ft_exec_parse(&ac, av);
	TOP_A = HEAD_A.next;
	TOP_B = &HEAD_B;
	if (!CURSE_MODE)
		ft_check_instruct();
	else
		ft_curse_instruct();
	ft_lst_moveto_prev(&HEAD_A, TOP_A);
	if (ft_exec_head_is_sorted() && !NB_ELEM_B)
		ft_printf("{GREEN:OK}\n");
	else
		ft_printf("{RED:KO}\n");
	ft_del_singl();
	return (0);
}
