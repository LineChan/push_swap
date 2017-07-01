#include "push_swap.h"
//#include <fcntl.h>

/*
** Check the instruction given by the push_swap program 
** and execute them
*/
void			ft_check_instruct(void)
{
	char	*line;
	while (get_next_line(0, &line) && ft_strcmp("", line))
	{
		//ft_printf("line : %s\n", line);
		if (!ft_check_do_instruct(line))
			EXIT_FAIL("Wrong instruction");
	}
}
