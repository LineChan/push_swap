#include "push_swap.h"

/*
**
*/
int				ft_ps_head_is_reverse_sorted(node head)
{
	node	it;

	if (head == &HEAD_B)
		it = TOP_B;
	else
		it = TOP_A;
	while (it->next != head)
	{
		if (DATA(it) < DATA(it->next))
			return (0);
		it = it->next;
	}
	return (1);
}
