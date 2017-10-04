/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_seven.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:49:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 16:09:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort lists with 4 - 7 elements
**
*/

void				ft_ps_sort_seven(void)
{
	while (NB_ELEM_A > 3)
		ft_exec_pb();
	ft_ps_sort_three();
	while (NB_ELEM_B)
		ft_ps_find_where_to_push(&HEAD_A, DATA(TOP_B));
	if (TOP_A != HEAD_A.next)
	{
		while ((DATA(TOP_A) > DATA(TOP_A->prev)) && (TOP_A->prev != &HEAD_A))
			ft_exec_rra();
	}
}
