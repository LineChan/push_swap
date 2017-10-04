/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_head_is_reverse_sorted.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:08:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 16:08:26 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if Stack B is reverse sorted
*/

int				ft_ps_head_is_reverse_sorted(const t_lst *head)
{
	t_lst		*it;

	if (head == &HEAD_B)
		it = HEAD_B.next;
	else
		it = HEAD_A.next;
	while (it->next != head)
	{
		if (DATA(it) < DATA(it->next))
			return (0);
		it = it->next;
	}
	return (1);
}
