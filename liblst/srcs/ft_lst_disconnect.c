/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_disconnect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:01:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/05 15:08:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Disconnet a node from a list and resets its next and prev poiters on itself
**
** 1st parameter : node to disconnect
*/

void				ft_lst_disconnect(t_lst *src)
{
	src->prev->next = src->next;
	src->next->prev = src->prev;
	src->next = src;
	src->prev = src;
}
