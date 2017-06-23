#include "push_swap.h"

/*
** Excute the moves given by push_swap
** Use left or right arrow to navigate
*/
void			ft_curse_do_instruct(void)
{
	int		ch;
	int		i;

	i = 0;
	noecho();
	while ((ch = getch()) != 10);
	wclear(CURSE);
	ft_curse_draw_border(CURSE);
	ft_curse_draw_border(SCORE);
	refresh();
	wrefresh(CURSE);
	wrefresh(SCORE);
	sleep(1);
	return ;
}
