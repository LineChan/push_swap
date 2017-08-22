/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_head_is_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 19:01:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:21:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Check if Stack A is sorted
*/
int				ft_exec_head_is_sorted(void)
{
	t_lst	*it;

	it = HEAD_A.next;
	while (it->next != &HEAD_A)
	{
		if (DATA(it) > DATA(it->next))
			return (0);
		it = it->next;
	}
	return (1);
}
