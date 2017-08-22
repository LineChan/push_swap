/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 16:21:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:01:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "liblst.h"

/*
** Sort a list using bubblesort
**
** 1st parameter : list to be sorted
** 2nd parameter : function to compare elements
*/
void			ft_lst_bubblesort(t_lst *lst, int (*f)(t_lst *, t_lst *))
{
	t_lst	*src;

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
