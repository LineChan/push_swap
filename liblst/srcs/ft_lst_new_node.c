/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 16:38:09 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/11 16:40:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Allocate a new t_lst node
*/
node			ft_lst_new_node(void)
{
	node		new;
	if (!(new = ft_memalloc(sizeof(t_lst))))
		return (0);
	INIT_LST_HEAD_P(new);
	return (new);
}
