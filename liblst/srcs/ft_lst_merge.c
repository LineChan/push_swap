/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:35:17 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/10 12:49:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Merge a list to the end of another one. Orders of both lists are preserved.
**
** 1st parameter : list to be merged
** 2nd parameter : destination list
*/
void                        ft_lst_merge(node src, node dst)
{
	dst->prev->next = src->next;
	src->next->prev = dst->prev;
	src->prev->next = dst;
	dst->prev = src->prev;
	INIT_LST_HEAD_P(src);
}
