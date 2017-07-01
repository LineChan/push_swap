#include "push_swap.h"
//#include <fcntl.h>

/*
** Check the instruction given by the push_swap program 
** and execute them
*/
void			ft_check_instruct(void)
{
	char	*line;
	int i = 0;
	while (get_next_line(0, &line) && ft_strcmp("", line))
	{
	++i;
		if (!ft_check_do_instruct(line))
			EXIT_FAIL("Wrong instruction");
	}
	ft_printf("NB_MOVE : %d\n", i);
}
