/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_selectsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:41:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/11 16:12:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/liblst.h"

/*
** Sort a list using selectsort
**
** 1st parameter : list to be sorted
** 2nd parameter : function to compare nodes
*/
static void					ft_selectsort_routine(node *lst,
													node *src,
													node *it,
													node *min,
													int (*f)(node, node))
{
	while ((f(*min, *it) <= 0) && ((*it)->next != *lst))
		*it = (*it)->next;
	if ((*min == *it) && ((*it)->next == *lst))
	{
		if ((*src)->next == *lst)
			return ;
		if (f(*src, *min) > 0)
			ft_lst_swap(*src, *min);
	}
	else
	{
		(f(*it, *min) > 0) ? ft_lst_swap(*src, *min) : ft_lst_swap(*src, *it);
		*src = *lst;
	}
}
void			ft_lst_selectsort(node lst, int (*f)(node, node))
{
	node		src;
	node		it;
	node		min;

	if (ft_lst_is_head(lst) || ft_lst_is_single(lst))
		return ;
	src = lst->next;
	while (src->next != lst)
	{
		it = src->next;
		while ((f(src, it) <= 0) && (it->next != lst))
			it = it->next;
		min = it;
		ft_selectsort_routine(&lst, &src, &it, &min, f);
		src = src->next;
	}
}
