/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:23:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/09 12:36:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*
** Executes			swap_a (swaps the 2 first nodes on Stack A)
** 					swap_b (swaps the 2 first nodes on Stack B)
** 					swap_s (swap_a & swap_b at the same time)
** and add the move to the instruction list
*/
void			ft_exec_sa(void)
{
	if (NB_ELEM_A > 1)
	{
		(TOP_A->next != &HEAD_A) ? ft_lst_swap(TOP_A, TOP_A->next) :
									ft_lst_swap(TOP_A, HEAD_A.next);
		TOP_A = (TOP_A->prev == &HEAD_A) ? HEAD_A.prev : TOP_A->prev;
		ft_exec_add_move("sa");
	}
}

void			ft_exec_sb(void)
{
	if (NB_ELEM_B > 1)
	{
		(TOP_B->next != &HEAD_B) ? ft_lst_swap(TOP_B, TOP_B->next) :
									ft_lst_swap(TOP_B, HEAD_B.next);
		TOP_B = (TOP_B->prev == &HEAD_B) ? HEAD_B.prev : TOP_B->prev;
		ft_exec_add_move("sb");
	}
}

void			ft_exec_ss(void)
{
	if ((NB_ELEM_A > 1) && (NB_ELEM_B > 1))
	{
		(TOP_A->next != &HEAD_A) ? ft_lst_swap(TOP_A, TOP_A->next) :
									ft_lst_swap(TOP_A, HEAD_A.next);
		TOP_A = (TOP_A->prev == &HEAD_A) ? HEAD_A.prev : TOP_A->prev;
		(TOP_B->next != &HEAD_B) ? ft_lst_swap(TOP_B, TOP_B->next) :
									ft_lst_swap(TOP_B, HEAD_B.next);
		TOP_B = (TOP_B->prev == &HEAD_B) ? HEAD_B.prev : TOP_B->prev;
	}
	else if ((NB_ELEM_A > 1) && (NB_ELEM_B < 2))
		ft_exec_sa();
	else if ((NB_ELEM_A < 2) && (NB_ELEM_B > 1))
		ft_exec_sb();
	ft_exec_add_move("ss");
}
