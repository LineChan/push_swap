#include "push_swap.h"
#include <fcntl.h>

/*
**
*/
void			ft_check_instruct(void)
{
	char	*line;
	int		fd;

	fd = open("result.txt", O_RDONLY);
	if (IS_NEG(fd))
		EXIT_FAIL("File not open");
	while (get_next_line(fd, &line) && ft_strcmp("", line))
	{
		if (!ft_check_do_instruct(line))
			EXIT_FAIL("Wrong instruction");
	}
	ft_lst_moveto_prev(&HEAD_A, TOP_A);
	PRINT_AB("RESULT CHECK");
	ft_printf("NB_MOVE : %d\n", NB_MOVE);

}
