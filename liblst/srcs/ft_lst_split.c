/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split_halves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:48:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:14:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
 ** Split a circular doubly linked list into two sublists
 **
 ** A fast pointer is stepping two nodes and a slow pointer is stepping one
 ** node through the list. When the fast pointer is at the head of the list,
 ** the slow one is at the middle. Then the two parts are made circular.
 ** If the length is odd, the extra node goes to the front list.
 **
 ** 1st parameter : list to be split
 ** 2nd parameter : front half
 ** 3rd parameter : back half
 */
void			ft_lst_split(t_lst *src, t_lst *front, t_lst *back)
{
	t_lst	*slow;
	t_lst	*fast;

	if (ft_lst_is_head(src) || ft_lst_is_single(src))
		return ;
	slow = src;
	fast = src;
	while (fast->next->next != src && fast->next != src)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	if (fast->next->next == src)
	{
		fast = fast->next;
		slow = slow->next;
	}
	back->next = slow->next;
	back->prev = fast;
	fast->next = back;
	slow->next->prev = back;
	front->next = src->next;
	front->prev = slow;
	slow->next = front;
	front->next->prev = front;
	INIT_LST_HEAD_P(src);
}
