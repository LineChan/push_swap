#include "push_swap.h"

/*
** Check the result given by push_swap
*/
int				main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	++av;
	--ac;
	if (!ft_strcmp("-x", *av))
	{
		CURSE_MODE =1;
		++av;
		--ac;
	}
	ft_exec_parse(ac, av);
	TOP_A = HEAD_A.next;
	TOP_B = &HEAD_B;
	if (!CURSE_MODE)
		ft_check_instruct();
	else
		ft_curse_instruct();
	//ft_printf("{RED:SEGFAULT main}\n");
	if (ft_exec_head_is_sorted(&HEAD_A) && !NB_ELEM_B)
		ft_printf("{GREEN:OK}\n");
	else
		ft_printf("{RED:KO}\n");
	return (0);
}
