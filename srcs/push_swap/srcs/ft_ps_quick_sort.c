#include "push_swap.h"

/*
** Sort a list using quicksort
*/
void			ft_ps_quick_sort(void)
{
	while (!ft_exec_head_is_sorted())
	{
		ft_ps_quick_a();
		if (ft_exec_head_is_sorted() && 
			((!NB_ELEM_B) || ft_ps_head_is_reverse_sorted(&HEAD_B)))
			break ;
		ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
		ft_ps_quick_b();
	}
	while (NB_ELEM_B)
		ft_exec_pa();
}
