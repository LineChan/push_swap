#include "push_swap.h"

/*
** 2nd part of the quicksort routine
*/
static int			ft_find_upper(node *left, int *pivot)
{
	while (DATA(*left) ^ *pivot)
	{
		if (DATA(*left) > *pivot)
			return (1);
		*left = (*left)->prev;
	}
	return (0);
}

static int			ft_elem_between_pivot(void)
{
	int		count;
	node	it;

	count = 0;
	it = TOP_B->next;
	while (!SORTED(it))
	{
		if (it == &HEAD_B)
			break ;
		it = it->next;
		++count;
	}
	return (count);
}

void				ft_stack_b_routine(node *left, int *size, int *pivot)
{
	*size = ft_elem_between_pivot() + 1;
	if (*size < 30)
		ft_quick_select(size, &DATA(TOP_B));
	else
	{
		ft_exec_rb();
		while (TOP_B != *left)
			(DATA(TOP_B) > *pivot) ? ft_exec_pa() : ft_exec_rb();
		ft_exec_pa();
		ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
		ft_ps_find_shortest_path(&HEAD_B, DATA(HEAD_B.next));
			if (DATA(TOP_A) > DATA(TOP_A->next))
				ft_exec_sa();
		ft_exec_pa();
	}
}

void				ft_ps_quick_b(void)
{
	int		pivot;
	int		size;
	node	left;

	while (NB_ELEM_B)
	{
		if (ft_ps_head_is_reverse_sorted(&HEAD_B))
			return ;
		pivot = DATA(TOP_B);
		if (SORTED(TOP_B))
		{
			ft_exec_pa();
		}
		else
		{
			SORTED(TOP_B) = 1;
			left = HEAD_B.prev;
			if (ft_find_upper(&left, &pivot))
				ft_stack_b_routine(&left, &size, &pivot);
			else
			{
				ft_exec_pa();
			}
		}
	}
}
