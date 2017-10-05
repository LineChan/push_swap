/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:01:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/05 15:18:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Swap two nodes in a circular doubly linked list.
**
** The idea is to use a matrix to describe states before and after the swap :
** (explanation based on non circular lists for clarity)
** For adjacent nodes : [X] - [A] - [B] - [Y]
**      A B               A B
** prev X A    =>    prev B X
** next B Y          next Y A
**
**      0 1    --\        2 0
**      2 3    --/        3 1
**
** For non adjacent nodes : [W] - [A] - [X] - ... - [Y] - [B] - [Z]
**      A B               A B
** prev W Y    =>    prev Y W
** next X Z          next Z X
**
**      0 1    --\        1 0
**      2 3    --/        3 2
** Adapted from : http://codepad.org/UHcmmag1
**
** 1st parameter : 1st node
** 2nd parameter : 2nd node
*/

static int			nodes_are_next(t_lst *a, t_lst *b)
{
	return ((a->next == b && b->prev == a) || (a->prev == b && b->next == a));
}

void				ft_lst_swap(t_lst *a, t_lst *b)
{
	t_lst	*tmp[4];

	tmp[0] = a->prev;
	tmp[1] = b->prev;
	tmp[2] = a->next;
	tmp[3] = b->next;
	if (nodes_are_next(a, b))
	{
		a->prev = tmp[2];
		b->prev = tmp[0];
		a->next = tmp[3];
		b->next = tmp[1];
	}
	else
	{
		a->prev = tmp[1];
		b->prev = tmp[0];
		a->next = tmp[3];
		b->next = tmp[2];
	}
	a->prev->next = a;
	a->next->prev = a;
	b->prev->next = b;
	b->next->prev = b;
}
