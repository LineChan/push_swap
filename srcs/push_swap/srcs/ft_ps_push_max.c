/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_push_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:32:39 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/11 11:16:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push element in decreasing order
**
** 1st parameter : list to be pushed
** 2nd paremeter : lenght of destination sublist
*/
void				ft_ps_push_max(const node head, const int len)
{
	int			ref;
	int			offset;
	node		it;

	offset = 0;
	it = head->next;
	ref = C_STACK(it)->data;
	while (offset < len)
	{
		ref = MAX(ref, C_STACK(it)->data);
		++offset;
		it = it->next;
	}
	ft_ps_find_shortest_path(head, ref);
	if (head == &HEAD_B)
		ft_exec_pa();
	else
		ft_exec_pb();
}
