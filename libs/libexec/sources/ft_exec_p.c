/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:48:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 23:38:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Executes			push_a (pop the top of Stack B to Stack A)
** 					push_b (pop the top of Stack A to Stack B)
** and adds the move to the instruction list
*/

void				ft_exec_pa(void)
{
	if (NB_ELEM_B)
	{
		TOP_B = TOP_B->next;
		ft_lst_moveto_prev(TOP_B->prev, TOP_A);
		(TOP_B == &HEAD_B) ? (TOP_B = TOP_B->next) : 0;
		--NB_ELEM_B;
		++NB_ELEM_A;
		TOP_A = TOP_A->prev;
		ft_exec_add_move("pa");
	}
}

void				ft_exec_pb(void)
{
	if (NB_ELEM_A)
	{
		TOP_A = TOP_A->next;
		ft_lst_moveto_prev(TOP_A->prev, TOP_B);
		(TOP_A == &HEAD_A) ? (TOP_A = TOP_A->next) : 0;
		--NB_ELEM_A;
		++NB_ELEM_B;
		TOP_B = TOP_B->prev;
		ft_exec_add_move("pb");
	}
}
