/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 10:46:03 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/05 15:06:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Delete a node by making the prev/next entries point to each other
**
** 1st parameter : node to be removed
*/

void		ft_lst_del(t_lst *ref)
{
	ref->next->prev = ref->prev;
	ref->prev->next = ref->next;
}
