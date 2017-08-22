/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rec_mergesort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:54:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:03:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Recursively sort a list using mergesort (top-down implementation)
**
** 1st parameter : list to be sorted
** 2nd parameter : function to compare nodes
*/
void				ft_lst_mergesort(t_lst *lst, int (*f)(t_lst *, t_lst *))
{
	t_lst	*src;
	t_lst	*a;
	t_lst	*b;

	if (ft_lst_is_single(lst) || ft_lst_is_head(lst))
		return ;
	if (!((a = ft_lst_new_node()) && (b = ft_lst_new_node())))
		return ;
	src = lst;
	ft_lst_split(src, a, b);
	ft_lst_mergesort(a, f);
	ft_lst_mergesort(b, f);
	ft_lst_sorted_merge(src, a, b, f);
}
