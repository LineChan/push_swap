#include "push_swap.h"

/*
 ** Draw borders (box) 
 **
 ** 1st parameter : screen where borders are going to be drawn
 */
void			ft_curse_draw_border(WINDOW *screen)
{
	int			x;
	int			y;
	int			i;

	getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+");
	i = 1;
	while (i < (y - 1))
	{
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
		++i;
	}
	i = 1;
	while (i < (x - 1))
	{
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
		++i;
	}
}
