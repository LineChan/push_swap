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
** Execute			swap_a (swap the 2 first nodes on Stack A)
** 					swap_b (swap the 2 first nodes on Stack B)
** 					swap_s (swap_a & swap_b at the same time)
** and add the move to the result linked list
*/
void			ft_exec_sa(void)
{
	if (NB_ELEM_A > 1)
	{
		(TOP_A->next != &HEAD_A) ? ft_lst_swap(TOP_A, TOP_A->next) :
									ft_lst_swap(TOP_A, TOP_A->next->next);
		TOP_A = (TOP_A->prev == &HEAD_A) ? TOP_A->prev->prev : TOP_A->prev;
		ft_exec_add_move("sa");
	}
}

void			ft_exec_sb(void)
{
	if (NB_ELEM_B > 1)
	{
		(TOP_B->next != &HEAD_B) ? ft_lst_swap(TOP_B, TOP_B->next) :
									ft_lst_swap(TOP_B, TOP_B->next->next);
		TOP_B = (TOP_B->prev == &HEAD_B) ? TOP_B->prev->prev : TOP_B->prev;
		ft_exec_add_move("sb");
	}
}

void			ft_exec_ss(void)
{
	if ((NB_ELEM_A > 1) && (NB_ELEM_B > 1))
	{
		(TOP_A->next != &HEAD_A) ? ft_lst_swap(TOP_A, TOP_A->next) :
									ft_lst_swap(TOP_A, TOP_A->next->next);
		TOP_A = (TOP_A->prev == &HEAD_A) ? TOP_A->prev->prev : TOP_A->prev;
		(TOP_B->next != &HEAD_B) ? ft_lst_swap(TOP_B, TOP_B->next) :
									ft_lst_swap(TOP_B, TOP_B->next->next);
		TOP_B = (TOP_B->prev == &HEAD_B) ? TOP_B->prev->prev : TOP_B->prev;
		ft_exec_add_move("ss");
	}
	else if ((NB_ELEM_A > 1) && (NB_ELEM_B < 2))
		ft_exec_sa();
	else if ((NB_ELEM_A < 2) && (NB_ELEM_B > 1))
		ft_exec_sb();
	}
