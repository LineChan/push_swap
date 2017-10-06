/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:34:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:10:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

void			ft_lst_foreach(t_lst *lst, void (*f)(t_lst *))
{
	t_lst	*it;

	if (ft_lst_is_head(lst))
		return ;
	it = lst->next;
	while (it != lst)
	{
		it = it->next;
		f(it->prev);
	}
}
