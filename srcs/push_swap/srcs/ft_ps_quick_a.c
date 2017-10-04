/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_quick_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:08:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 17:40:26 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 1st part of quicksort routine
*/

static int		ft_there_is_left_to_sort(t_lst **left, int *pivot)
{
	while (DATA((*left)->next) ^ *pivot)
	{
		if (DATA(*left) < *pivot)
			return (1);
		*left = (*left)->next;
	}
	return (0);
}

static void		ft_push_lower(t_lst **left, int *pushed, int *pivot)
{
	int		step;

	step = ft_ps_count_step(&HEAD_A, DATA(*left));
	if (step < (NB_ELEM_A >> 1))
		while (TOP_A != *left)
			ft_exec_ra();
	else
	{
		ft_exec_rra();
		while (TOP_A != *left)
		{
			if (DATA(TOP_A) < *pivot)
			{
				ft_exec_pb();
				++*pushed;
			}
			ft_exec_rra();
		}
	}
	ft_exec_pb();
	++*pushed;
}

static void		ft_stack_a_routine(int *pushed, int *pivot)
{
	ft_ps_find_shortest_path(&HEAD_A, *pivot);
	if (!(ft_exec_head_is_sorted()
			&& (ft_ps_head_is_reverse_sorted(&HEAD_B) || !NB_ELEM_B)))
		pushed = 0;
	if (NB_ELEM_A > 2)
		ft_exec_pb();
}

void			ft_ps_quick_a(void)
{
	int		pivot;
	int		pushed;
	t_lst	*left;

	pushed = 0;
	while (NB_ELEM_A > 1)
	{
		pivot = DATA(HEAD_A.next);
		SORTED(HEAD_A.next) = 1;
		left = TOP_A;
		if (ft_there_is_left_to_sort(&left, &pivot))
		{
			ft_push_lower(&left, &pushed, &pivot);
			if (ft_exec_head_is_sorted())
			{
				ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
				break ;
			}
		}
		else
			ft_stack_a_routine(&pushed, &pivot);
	}
}
