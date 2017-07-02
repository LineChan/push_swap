#include "push_swap.h"

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
