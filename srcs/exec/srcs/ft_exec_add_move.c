#include "push_swap.h"

/*
**
*/
void			ft_exec_add_move(char const *exec)
{
	t_result		*new;

	if (!(new = ft_memalloc(sizeof(t_result))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	new->move = ft_strdup(exec);
	ft_lst_add_prev(&new->lst, &INFO);
	++NB_MOVE;
}
