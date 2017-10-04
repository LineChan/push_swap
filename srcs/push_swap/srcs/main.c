#include "push_swap.h"

/*
**	Sort parameters in increasing order
*/
int					main(int ac, char **av)
{
	int		clean;
	int		x;

	if (ac == 1)
		EXIT_FAIL("");
	++av;
	--ac;
	clean = 0;
	x = 0;
	if (!ft_strcmp("--clean", *av))
	{
		--ac;
		++av;
		if (ac < 2)
			EXIT_FAIL("Error (no argument)");
		else
		++clean;
	}
	if (!ft_strcmp("-x", *av))
	{
		--ac;
		++av;
		if (!ac)
			EXIT_FAIL("Error (no argument)");
		else
			x = 1;
	}
	ft_exec_parse(&ac, av);
	ft_ps_sort();
	if (clean)
		ft_ps_clean_result();
	if (x)
		ft_print_result_ps();
	else
		ft_lst_foreach(&INFO, &ft_print_result_list);
	return (0);
}
