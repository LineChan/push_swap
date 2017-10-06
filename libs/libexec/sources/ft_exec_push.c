/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:02:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 16:02:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Allocate a new node and add it to the end of Stack A
**
** 1st parameter : integer to sort
*/

void			ft_exec_push(const int nb)
{
	t_stack		*new;

	if (!(new = ft_memalloc(sizeof(t_stack))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	new->data = nb;
	new->sorted = 0;
	ft_lst_add_prev(&new->lst, &HEAD_A);
	++NB_ELEM_A;
}
