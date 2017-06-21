#include "push_swap.h"

/*
**	Sort parameters in increasing order
*/
int					main(int ac, char **av)
{
	if (ac == 1)
		EXIT_FAIL("");
	// clean
	++av;
	--ac;
	ft_exec_parse(ac, av);
	return (0);
}
