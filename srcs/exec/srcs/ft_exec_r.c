/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 20:10:41 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/09 12:37:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Execute		rotate_a (first node  moved to the end of Stack A)
** 				rotate_b (first node  moved to the end of Stack B)
** 				rotate_r (rotate Stack A and Stack B)
** and add the move to the result linked list
*/
void			ft_exec_ra(void)
{
	if (NB_ELEM_A > 1)
	{
		TOP_A = (TOP_A->next == &HEAD_A) ? HEAD_A.next : TOP_A->next;
		ft_exec_add_move("ra");
	}
}

void			ft_exec_rb(void)
{
	if (NB_ELEM_B > 1)
	{
		TOP_B = (TOP_B->next == &HEAD_B) ? HEAD_B.next : TOP_B->next;
		ft_exec_add_move("rb");
	}
}

void			ft_exec_rr(void)
{
	if ((NB_ELEM_A > 1) && (NB_ELEM_B > 1))
	{
		TOP_A = (TOP_A->next == &HEAD_A) ? HEAD_A.next : TOP_A->next;
		TOP_B = (TOP_B->next == &HEAD_B) ? HEAD_B.next : TOP_B->next;
		ft_exec_add_move("rr");
	}
	else if ((NB_ELEM_A > 1) && (NB_ELEM_B < 2))
		ft_exec_ra();
	else if ((NB_ELEM_A < 2) && (NB_ELEM_B > 1))
		ft_exec_rb();

}
