#include "push_swap.h"

/*
**	Sort parameters in increasing order
*/
int					main(int ac, char **av)
{
	int **array;

	if (ac == 1)
		EXIT_FAIL("");
	// clean
	++av;
	--ac;
	if (!(array = (int **)ft_memalloc(sizeof(int *) * ac)))
		EXIT_FAIL("Failed memory allocation");
	ft_exec_parse(ac, av, array);
	return (0);
}
