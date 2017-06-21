/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_find_shortest_path.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:03:09 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/15 13:00:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Find the shortest way to a node
**
** 1st parameter : head of the list to go through
** 2nd parameter : integer to find in the list
*/


void					ft_ps_find_shortest_path(node head, int ref)
{
	int			step;

	step = ft_ps_count_step(head, ref);
	if (head == &HEAD_B)
	{
		//if (step < (NB_ELEM_B - step))
		if (step < (NB_ELEM_B >> 1))
			while (DATA(TOP_B) != ref)
				ft_exec_rb();
		else
			while (DATA(TOP_B) != ref)
				ft_exec_rrb();
	}
	else
	{
		//if (step < (NB_ELEM_A - step))
		if (step < (NB_ELEM_A >> 1))
			while (DATA(TOP_A) != ref)
				ft_exec_ra();
		else
			while (DATA(TOP_A) != ref)
				ft_exec_rra();
	}
}
