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

	x = 2;
	y = 3;
	getmaxyx(CURSE, parent_y, parent_x);
	//it = &INFO;
	//it = it->next;
	if ((TOP_CURSE->prev != &INFO) && (TOP_CURSE != &INFO))
		mvwprintw(SCORE, y, 8, "%s  ", MOVE(TOP_CURSE->prev));
	x += 10;
	mvwprintw(SCORE, y, x, "<---- ");
		x += 10;
	if (TOP_CURSE == &INFO)
		mvwprintw(SCORE, y, x, "start");
	else
		mvwprintw(SCORE, y, x, "%s  ", MOVE(TOP_CURSE));
	x += 10;
	mvwprintw(SCORE, y, x, " ---->");
	if (TOP_CURSE != INFO.prev)
		wprintw(SCORE, "  %s", MOVE(TOP_CURSE->next));
#if 0
	while (it != &INFO)
	{
		/*
		   mvwprintw(SCORE, y, x, "%s", MOVE(it));
		   if (TOP_CURSE == it)
		   {
		   wattron(SCORE, COLOR_PAIR(2));
		   mvwprintw(SCORE, y + 1, x, "%c",'^');
		   wattroff(SCORE, COLOR_PAIR(2));
		   }
		   wrefresh(SCORE);
		   */
		it = it->next;
		x += 4;
		if (x > (parent_x - 4))
		{
			x = 9;
			y += 2;
		}
		//x += 2 + ft_strlen(MOVE(it));
	}
#endif
	return ;
}
