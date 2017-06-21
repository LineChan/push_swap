/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_find_where_to_push.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:29:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/22 14:31:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*
** Find the place of an element in a list
**
** 1st parameter : head of the destination list
** 2st parameter : int value of the node to be pushed
*/
void			ft_ps_find_where_to_push(node head, int ref)
{
	int			next;
	node		it;

	it = head->next;
	next = DATA(it);
	while (it != head)
	{
		if ((next < ref) ||
				((next > DATA(it)) && (DATA(it) > ref)))
			next = DATA(it);
		it = it->next;
	}
	if (next < ref)
	{
		ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
		ft_exec_pa();
		ft_lst_moveto_next(&HEAD_A, TOP_A);
	}
	else if (next > ref)
	{
		ft_ps_find_shortest_path(&HEAD_A, next);
		ft_exec_pa();
	}
}
