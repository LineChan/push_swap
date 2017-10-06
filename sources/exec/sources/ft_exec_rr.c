/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:37:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 16:06:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Executes		reverse_rotate_a (last element comes first on Stack A)
**				reverse_rotate_b (last element comes first on Stack B)
**				reverse_rotate_r (reverse rotate Stack A and Stack B)
** and adda the move to the instruction list
*/

void			ft_exec_rra(void)
{
	if (NB_ELEM_A > 1)
	{
		TOP_A = (TOP_A->prev == &HEAD_A) ? HEAD_A.prev : TOP_A->prev;
		ft_exec_add_move("rra");
	}
}

void			ft_exec_rrb(void)
{
	if (NB_ELEM_B > 1)
	{
		TOP_B = (TOP_B->prev == &HEAD_B) ? HEAD_B.prev : TOP_B->prev;
		ft_exec_add_move("rrb");
	}
}

void			ft_exec_rrr(void)
{
	if ((NB_ELEM_A > 1) && (NB_ELEM_B > 1))
	{
		TOP_A = (TOP_A->prev == &HEAD_A) ? HEAD_A.prev : TOP_A->prev;
		TOP_B = (TOP_B->prev == &HEAD_B) ? HEAD_B.prev : TOP_B->prev;
	}
	else if ((NB_ELEM_A > 1) && (NB_ELEM_B < 2))
		ft_exec_rra();
	else if ((NB_ELEM_A < 2) && (NB_ELEM_B > 1))
		ft_exec_rra();
	ft_exec_add_move("rrr");
}
