/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_quicksort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:32:08 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/19 09:58:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/liblst.h"
/*
 **
 */
static void		ft_partition(node src,
							node *front,
							node *back,
							int (*f)(node, node))
{
	node                it;

	it = (src)->next;
	while (it->next != src)
	{
		if (f(it->next, (src)->next) <= 0)
			ft_lst_moveto_prev(it->next, *front);
		else
			ft_lst_moveto_prev(it->next, *back);
	}
	ft_lst_moveto_prev((src)->next, *front);
}

void			ft_lst_quicksort(node lst, int (*f)(node, node))
{
	node		src;
	node		a;
	node		b;

	if (ft_lst_is_head(lst) || ft_lst_is_single(lst))
		return ;
	if (!((a = ft_lst_new_node())  && (b = ft_lst_new_node())))
		return ;
	src = lst;
	ft_partition(src, &a, &b, f);
	ft_lst_quicksort(a, f);
	ft_lst_quicksort(b, f);
	if (!ft_lst_is_head(b))
		ft_lst_merge(b,a);
	if (!ft_lst_is_head(a))
		ft_lst_merge(a, lst);
}
