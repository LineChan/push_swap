/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_add_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:56:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/10 20:10:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Adds a move to the instruction list
**
** 1st parameter : instructionn to be added
*/

void			ft_exec_add_move(const char *exec)
{
	t_result		*new;

	if (!(new = ft_memalloc(sizeof(t_result))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	ft_strcpy(new->move, exec);
	ft_lst_add_prev(&new->lst, &INFO);
	++NB_MOVE;
}
