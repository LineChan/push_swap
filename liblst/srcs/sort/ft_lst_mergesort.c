/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rec_mergesort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 14:54:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/11 16:39:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/liblst.h"

/*
** Recursively sort a list using mergesort (top-down implementation)
**
** 1st parameter : list to be sorted
** 2nd parameter : function to compare nodes
*/
void				ft_lst_mergesort(node lst, int (*f)(node, node))
{
	node	src;
	node	a;
	node	b;

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
