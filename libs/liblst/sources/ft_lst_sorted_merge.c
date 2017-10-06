/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sorted_merge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:24:36 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:14:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Merge two sorted lists in a sorted list
**
** 1st parameter : destination node (empty list)
** 2nd parameter : head of the 1st list to merge
** 3rd parameter : head of the 2nd list to merge
** 4th parameter : function to order the lists
*/
void                        ft_lst_sorted_merge(t_lst *dst,
												t_lst *a,
												t_lst *b,
												int (*f)(t_lst *a, t_lst *b))
{
	t_lst		*a_ptr;
	t_lst		*b_ptr;

	if (!ft_lst_is_head(dst))
		return ;
	a_ptr = a;
	b_ptr = b;
	while (a_ptr->next != a && b_ptr->next != b)
	{
		if (f(a_ptr->next, b_ptr->next) <= 0)
			ft_lst_moveto_prev(a_ptr->next, dst);
		if (f(a_ptr->next, b_ptr->next) > 0)
			ft_lst_moveto_prev(b_ptr->next, dst);
	}
	if (b_ptr->next != b)
		ft_lst_merge(b_ptr, dst);
	if (a_ptr->next != a)
		ft_lst_merge(a_ptr, dst);
	return ;
}
