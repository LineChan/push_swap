/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_moveto_prev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:07:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:12:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Mode a node from a list to the end of another list
**
** 1st parameter : node to be moved
** 2nd parameter : destination node
*/
void				ft_lst_moveto_prev(t_lst *src, t_lst *dst)
{
	ft_lst_disconnect(src);
	ft_lst_add_prev(src, dst);
}
