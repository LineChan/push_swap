#include "push_swap.h"

/*
** Adds a move to the instruction list
**
** 1st parameter : instructionn to be added
*/
void			ft_exec_add_move(const char *exec)
{
	t_result		*new;

	if (!(new = ft_memalloc(sizeof(t_result))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	new->move = ft_strdup(exec);
	ft_lst_add_prev(&new->lst, &INFO);
	++NB_MOVE;
}
