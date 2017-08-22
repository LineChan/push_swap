/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_selectsort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 20:41:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:08:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Sort a list using selectsort
**
** 1st parameter : list to be sorted
** 2nd parameter : function to compare nodes
*/
static void					ft_selectsort_routine(t_lst **lst,
													t_lst **src,
													t_lst **it,
													t_lst **min,
													int (*f)(t_lst *, t_lst *))
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
void			ft_lst_selectsort(t_lst *lst, int (*f)(t_lst *, t_lst *))
{
	t_lst	*src;
	t_lst	*it;
	t_lst	*min;

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
