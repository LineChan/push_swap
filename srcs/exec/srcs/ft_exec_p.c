/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:48:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/09 12:27:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Execute			push_a (move the 1st node of Stack B to Stack A)
** 					push_b (move the 1st node of Stack A to Stack B)
** and add the move to the result linked list
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
		ft_exec_add_move("pa");
		TOP_A = TOP_A->prev;
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
