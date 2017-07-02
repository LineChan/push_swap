#include "push_swap.h"

/*
** Checks if Stack B is reverse sorted
*/
int				ft_ps_head_is_reverse_sorted(node head)
{
	node	it;

	if (head == &HEAD_B)
		it = HEAD_B.next;
	else
		it = HEAD_A.next;
	while (it->next != head)
	{
		if (DATA(it) < DATA(it->next))
			return (0);
		it = it->next;
	}
	return (1);
}
