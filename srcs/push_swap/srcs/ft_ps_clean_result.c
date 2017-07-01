#include "push_swap.h"

/*
# define NEXT(it, move1, move2) (!ft_strcmp(MOVE(it), move1) && \
		(!ft_strcmp(MOVE(it->next), move2)))
*/

/*
 ** Clean results and remove redondant patterns
 */
void		ft_ps_clean_push(node it)
{
	if ((it == &INFO) || (it->next == &INFO))
		return ;
	if (NEXT(it, "pa", "pb") || NEXT(it, "pb", "pa"))
	{
		ft_lst_del(it);
		ft_lst_del(it->next);
		NB_MOVE -= 2;
	}
}

void		ft_ps_clean_rotate(node it)
{
	if ((it == &INFO) || (it->next == &INFO))
		return ;
	if (NEXT(it, "ra", "rra") || NEXT(it, "rra", "ra") ||
			NEXT(it, "rb", "rrb") || NEXT(it, "rrb", "rb"))
	{
		ft_lst_del(it);
		ft_lst_del(it->next);
		NB_MOVE -= 2;
	}
}

void		ft_ps_clean_double(node it)
{
	if ((			it == &INFO) || (it->next == &INFO))
		return ;
	if (NEXT(it, "ra", "rb") || NEXT(it, "rb", "ra"))
	{
		MOVE(it) = "rr";
		ft_lst_del(it->next);
		--NB_MOVE;
	}
	if (NEXT(it, "rra", "rrb") || NEXT(it, "rrb", "rra"))
	{
		MOVE(it) = "rrr";
		ft_lst_del(it->next);
		--NB_MOVE;
	}
	if (NEXT(it, "sa", "sb") || NEXT(it, "sb", "sa"))
	{
		MOVE(it) = "ss";
		ft_lst_del(it->next);
		--NB_MOVE;
	}
	if (NEXT(it, "rr", "rrr") || NEXT(it, "rrr", "rr"))
	{
		ft_lst_del(it);
		ft_lst_del(it->next);
		NB_MOVE -= 2;
	}
}

void		ft_ps_clean_result(void)
{
	node	it;

	it = INFO.next;
	ft_lst_foreach(it, &ft_ps_clean_push);
	it = INFO.next;
	ft_lst_foreach(it, &ft_ps_clean_rotate);
	it = INFO.next;
	ft_lst_foreach(it, &ft_ps_clean_double);
}
