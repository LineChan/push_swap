/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:37:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/09 12:43:20 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Execute	reverse_rotate_a (last node moved to the beginning of Stack A)
** 			reverse_rotate_b (last node moved to the beginning of Stack B)
** 			reverse_rotate_r (reverse rotate Stack A and Stack B)
** and add the move to the result linked list
*/
void			ft_exec_rra(void)
{
	if (NB_ELEM_A > 1)
	{
		TOP_A = (TOP_A->prev == &HEAD_A) ? HEAD_A.prev : TOP_A->prev;
		//PRINT_AB("rra");
		ft_exec_add_move("rra");
		//ft_printf("rra ");
	}
}

void			ft_exec_rrb(void)
{
	if (NB_ELEM_B > 1)
	{
		TOP_B = (TOP_B->prev == &HEAD_B) ? HEAD_B.prev : TOP_B->prev;
		//PRINT_AB("rrb");
		ft_exec_add_move("rrb");
		//ft_printf("rrb ");
	}
}

void			ft_exec_rrr(void)
{
	if ((NB_ELEM_A > 1) && (NB_ELEM_B > 1))
	{
		TOP_A = (TOP_A->prev == &HEAD_A) ? HEAD_A.prev : TOP_A->prev;
		TOP_B = (TOP_B->prev == &HEAD_B) ? HEAD_B.prev : TOP_B->prev;
		//ft_printf("rrr ");
		ft_exec_add_move("rrr");
		//PRINT_AB("rrr");
	}
	else if ((NB_ELEM_A > 1) && (NB_ELEM_B < 2))
		ft_exec_rra();
	else if ((NB_ELEM_A < 2) && (NB_ELEM_B > 1))
		ft_exec_rra();
}
