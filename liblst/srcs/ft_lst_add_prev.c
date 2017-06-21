/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:45:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/10 09:52:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Add a node to the end of another list
**
** 1st parameter : new node
** 2nd parameter : destination node
*/

void				ft_lst_add_prev(node new, node dst)
{
	new->prev = dst->prev;
	new->next = dst;
	dst->prev->next = new;
	dst->prev = new;
}
