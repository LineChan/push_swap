/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_head_is_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:01:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/10 09:54:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if the head is sorted
**
** 1st parameter : head to be checked
*/
int				ft_exec_head_is_sorted(node head)
{
	node	it;

	it = head->next;
	while (it->next != head)
	{
		if (DATA(it) > DATA(it->next))
			return (0);
		it = it->next;
	}
	/*
	if (head == &HEAD_A)
		if (ft_find_shortest_path(head) < 0)
			while (TOP_A != head->next)
				ft_exec_ra();
		else
			while (TOP_A != head->next)
				ft_exec_rra();
	else
		if (ft_find_shortest_path(head) < 0)
			while (TOP_B != head->next)
				ft_exec_rb();
		else
			while (TOP_B != head->next)
				ft_exec_rrb();
				*/
	return (1);
}
