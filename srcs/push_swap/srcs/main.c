#include "push_swap.h"

/*
**	Sort parameters in increasing order
*/
int					main(int ac, char **av)
{
	int		clean;

	if (ac == 1)
		EXIT_FAIL("");
	// clean
	++av;
	--ac;
	clean = 0;
	if (!ft_strcmp("-clean", *av))
	{
		--ac;
		++av;
		if (!ac)
			EXIT_FAIL("Error (no argument)");
		else
		++clean;
	}
	ft_exec_parse(ac, av);
	ft_ps_sort();
	ft_printf("NB_MOVE : %d\n", NB_MOVE);
	ft_print_result_ps();
	if (clean)
		ft_ps_clean_result();
	PRINT_AB("RESULT");
	ft_printf("NB_MOVE : %d\n", NB_MOVE);
	ft_print_result_ps();
	return (0);
}
