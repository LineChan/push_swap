#include "push_swap.h"

/*
** Singletons functions
*/
t_info			*push_swap(void)
{
	static t_info		*ptr = 0;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_info))))
	{
		INIT_LST_HEAD(ptr->lst_info);
		ptr->nb_move = 0;
		ptr->nb_elem = 0;
	}
	return (ptr);
}
