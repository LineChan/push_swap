#include "push_swap.h"

/*
** Check the instruction given by the push_swap program 
** and execute them
*/
void			ft_check_instruct(void)
{
	char	*line;

	while ((line = ft_gnt(0, '\n')) && ft_strcmp("", line))
	{
		if (!ft_check_do_instruct(line))
			EXIT_FAIL("Wrong instruction");
	}
}
