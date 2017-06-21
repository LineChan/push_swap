/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:21:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/11 21:18:05 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/liblst.h"

/*
** Sort a list using bubblesort
**
** 1st parameter : list to be sorted
** 2nd parameter : function to compare elements
*/
void			ft_lst_bubblesort(node lst, int (*f)(node, node))
{
	node        src;

	if (ft_lst_is_head(lst) || ft_lst_is_single(lst))
		return ;
	src = lst->next;
	while (src->next != lst)
	{
		if (f(src, src->next) > 0)
		{
			ft_lst_swap(src, src->next);
			src = lst;
		}
		src = src->next;
	}
}
