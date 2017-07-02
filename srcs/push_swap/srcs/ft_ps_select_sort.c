/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_select_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:58:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/10 13:30:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Select sort a list
** Push MIN to Stack B until there are only 3 elems left. Use
** three_sort, then push everything back to Stack A
**
*/
static void		ft_push_min(void)
{
	int		ref;
	int		offset;
	node	it;

	offset = 0;
	it = HEAD_A.next;
	ref = DATA(it);
	while (offset < NB_ELEM_A)
	{
		ref = MIN(ref, DATA(it));
		++offset;
		it = it->next;
	}
	ft_ps_find_shortest_path(&HEAD_A, ref);
	ft_exec_pb();
}

void			ft_ps_select_sort(void)
{
	int		len;

	len = NB_ELEM_A;
	while (len > 3)
	{
		ft_push_min();
		if (ft_exec_head_is_sorted())
			break ;
		--len;
	}
	ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
	ft_ps_sort_three();
	ft_lst_moveto_prev(&HEAD_A, TOP_A);
	ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
	while (NB_ELEM_B)
		ft_exec_pa();
}
