/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:14:56 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 17:15:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Add a structure to the beginning of another list
**
** 1st parameter : new node
** 2nd parameter : destination node
*/

void			ft_lst_add_next(t_lst *new, t_lst *dst)
{
	dst->next->prev = new;
	new->next = dst->next;
	new->prev = dst;
	dst->next = new;
}
