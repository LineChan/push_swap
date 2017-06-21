#include "push_swap.h"

static void		ft_convert_arg(int **array, const char *s)
{
	int		word;

	word = ft_count_word(s, ' ');
	if (!ft_strlen(s) || !word)
		EXIT_FAIL("Error (null or empty string");
	if (!(*(array + NB_ELEM) = (int *)ft_memalloc(word * sizeof(int))))
		EXIT_FAIL("Failed memory allocation");
	++array;
	++s;
}

void			ft_exec_parse(int ac, char **av, int **array)
{
	int		n;

	n = 0;
	ft_printf("exec parse\n");
	while (n < ac)
	{
		ft_convert_arg(array, *av);
		++av;
		++n;
	}
}
