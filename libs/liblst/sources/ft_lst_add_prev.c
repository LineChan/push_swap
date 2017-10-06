/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:45:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:08:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Add a node to the end of another list
**
** 1st parameter : new node
** 2nd parameter : destination node
*/

void				ft_lst_add_prev(t_lst *new, t_lst *dst)
{
	new->prev = dst->prev;
	new->next = dst;
	dst->prev->next = new;
	dst->prev = new;
}
