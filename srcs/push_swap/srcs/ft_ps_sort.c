#include "push_swap.h"

/*
** Select a sort type according to the number of elements to sort
*/

void			ft_ps_sort(void)
{
	if (ft_exec_head_is_sorted() || (NB_ELEM_A == 1))
		return ;
	TOP_A = HEAD_A.next;
	TOP_B = &HEAD_B;
	if (NB_ELEM_A == 2)
	{
		if (DATA(TOP_A) > DATA(TOP_A->next))
			ft_exec_sa();
	}
	else if (NB_ELEM_A == 3)
		ft_ps_sort_three();
	else if (NB_ELEM_A < 7)
		ft_ps_sort_seven();
	else if (NB_ELEM_A < 20)
		ft_ps_select_sort();
	else
		ft_ps_quick_sort();
}
