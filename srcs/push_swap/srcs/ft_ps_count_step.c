/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_count_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:26:15 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/22 14:27:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Count the number of moves to go to a reference from the top of a stack
**
** 1st parameter : head of the list the reference is
** 2nd parameter : reference to find
*/
int					ft_ps_count_step(const node head, const int ref)
{
	int			step;;
	node		it;;

	step = 0;
	if (head == &HEAD_B)
		it = TOP_B;
	else
		it = TOP_A;
	while (DATA(it) != ref)
	{
		it = it->next;
		if (it == head)
			it = it->next;
		++step;
	}
	return (step);
}
