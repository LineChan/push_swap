/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_clean_result.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:07:48 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 17:40:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Clean results and remove redondant patterns
*/

static void		ft_ps_clean_push(t_lst *it)
{
	if ((it == &INFO) || (it->next == &INFO))
		return ;
	if (NEXT(it, "pa", "pb") || NEXT(it, "pb", "pa"))
	{
		ft_lst_del(it);
		ft_lst_del(it->next);
		NB_MOVE -= 2;
	}
}

static void		ft_ps_clean_rotate(t_lst *it)
{
	if ((it == &INFO) || (it->next == &INFO))
		return ;
	if (NEXT(it, "ra", "rra") || NEXT(it, "rra", "ra") ||
			NEXT(it, "rb", "rrb") || NEXT(it, "rrb", "rb"))
	{
		ft_lst_del(it);
		ft_lst_del(it->next);
		NB_MOVE -= 2;
	}
}

static void		ft_ps_del_node(t_lst *it, char *move)
{
	MOVE(it) = move;
	ft_lst_del(it);
	--NB_MOVE;
}

static void		ft_ps_clean_double(t_lst *it)
{
	if ((it == &INFO) || (it->next == &INFO))
		return ;
	if (NEXT(it, "ra", "rb") || NEXT(it, "rb", "ra"))
		ft_ps_del_node(it->next, "rr");
	if (NEXT(it, "rra", "rrb") || NEXT(it, "rrb", "rra"))
		ft_ps_del_node(it->next, "rrr");
	if (NEXT(it, "sa", "sb") || NEXT(it, "sb", "sa"))
		ft_ps_del_node(it->next, "ss");
	if (NEXT(it, "rr", "rrr") || NEXT(it, "rrr", "rr"))
	{
		ft_lst_del(it);
		ft_lst_del(it->next);
		NB_MOVE -= 2;
	}
}

void			ft_ps_clean_result(void)
{
	t_lst	*it;

	it = INFO.next;
	ft_lst_foreach(it, &ft_ps_clean_push);
	it = INFO.next;
	ft_lst_foreach(it, &ft_ps_clean_rotate);
	it = INFO.next;
	ft_lst_foreach(it, &ft_ps_clean_double);
}
