/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_moveto_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:05:03 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 17:16:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Move a node from a list the to beginning of another list
**
** 1st parameter : node to be moved
** 2nd parameter : destination node
*/

void					ft_lst_moveto_next(t_lst *src, t_lst *dst)
{
	ft_lst_disconnect(src);
	ft_lst_add_next(src, dst);
}
