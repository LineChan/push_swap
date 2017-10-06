/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:02:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 16:02:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Singletons functions
*/

t_info			*push_swap(void)
{
	static t_info		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_info))))
	{
		INIT_LST_HEAD(ptr->lst_info);
		ptr->nb_move = 0;
	}
	return (ptr);
}

t_head			*stack_a(void)
{
	static t_head		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_head))))
	{
		INIT_LST_HEAD(ptr->lst_head);
		ptr->nb_elem = 0;
	}
	return (ptr);
}

t_head			*stack_b(void)
{
	static t_head		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_head))))
	{
		INIT_LST_HEAD(ptr->lst_head);
		ptr->nb_elem = 0;
	}
	return (ptr);
}
