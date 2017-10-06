/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnode _add_struct_to_node.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:55:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:08:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"
/*
** Add a structure to the beginning of another list
**
** 1st parameter : new node
** 2nd parameter : destination node
*/
void			ft_lst_add_next(t_lst * new, t_lst * dst)
{
	dst->next->prev = new;
	new->next = dst->next;
	new->prev = dst;
	dst->next = new;
}
