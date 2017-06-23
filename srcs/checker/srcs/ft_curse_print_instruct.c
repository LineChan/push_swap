#include "push_swap.h"

/*
** Print all the moves in the score screen
*/
void			ft_curse_print_instruct(void)
{
	int		x;
	int		y;
	int		parent_x;
	int		parent_y;
	node	it;

	it = &INFO;
	x = 2;
	y = 3;
	getmaxyx(CURSE, parent_y, parent_x);
	mvwprintw(SCORE, y, x, "Start");
	if (TOP_CURSE == &INFO)
	{
		wattron(SCORE, COLOR_PAIR(2));
		mvwprintw(SCORE, y + 1, x, "%c",'^');
		wattroff(SCORE, COLOR_PAIR(2));
	}
	x = 9;
	it = it->next;
	while (it != &INFO)
	{
		mvwprintw(SCORE, y, x, "%s", MOVE(it));
		if (TOP_CURSE == it)
		{
			wattron(SCORE, COLOR_PAIR(2));
			mvwprintw(SCORE, y + 1, x, "%c",'^');
			wattroff(SCORE, COLOR_PAIR(2));
		}
		wrefresh(SCORE);
		it = it->next;
		x += 4;
		if (x > (parent_x - 4))
		{
			x = 9;
			y += 2;
		}
		//x += 2 + ft_strlen(MOVE(it));
	}
	return ;
}
