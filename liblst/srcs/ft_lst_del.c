/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 10:46:03 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/20 10:48:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Delete a node by making the prev/next entries point to each other
**
** 1st parameter : node to be removed
*/
void		ft_lst_del(node ref)
{
	ref->next->prev = ref->prev;
	ref->prev->next = ref->next;
}
