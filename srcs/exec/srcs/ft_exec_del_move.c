#include "push_swap.h"

/*
** Delete a node
**
** 1st parameter : pointer to the node to be removed
*/
void			ft_exec_del_move(t_result **ptr)
{
	if (!*ptr)
	{
		ft_strdel((char **) (*ptr)->move);
		ft_memdel((void **)ptr);
		*ptr = 0;
	}
}
