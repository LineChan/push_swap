#include "push_swap.h"

/*
** Print all the moves in the score screen
*/
void			ft_curse_print_instruct(void)
{
	//int		x;
	int		parent_x;

	//x = 2;
	//getmax x only?
	getmaxyx(SCORE, parent_x, parent_x);
	if ((TOP_CURSE->prev != &INFO) && (TOP_CURSE != &INFO))
	{
		mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) - 20,
				"%s  ", MOVE(TOP_CURSE->prev));
	}
	//x += 10;
	wattron(SCORE, COLOR_PAIR(2));
	mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) - 10, "<---- ");
	wattroff(SCORE, COLOR_PAIR(2));
		//x += 10;
	if (TOP_CURSE == &INFO)
		mvwprintw(SCORE, (SCORE_SIZE >> 1), (parent_x >> 1), "start");
	else
		mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) + 2,
				"%s  ", MOVE(TOP_CURSE));
	//x += 10;
	wattron(SCORE, COLOR_PAIR(2));
	mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) + 10, " ---->");
	wattroff(SCORE, COLOR_PAIR(2));
	if (TOP_CURSE != INFO.prev)
		wprintw(SCORE, "  %s", MOVE(TOP_CURSE->next));
	return ;
}
