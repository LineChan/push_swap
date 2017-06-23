#include "push_swap.h"

/*
**
*/
void			ft_curse_print_stack(void)
{
	int		parent_x;
	int		parent_y;
	int		x;
	int		y;
	node	it;

	x = 2;
	getmaxyx(CURSE, parent_y, parent_x);
	mvwprintw(CURSE, (parent_y >> 1) - 3, x, "Stack A");
	wattron(CURSE, COLOR_PAIR(2));
	wprintw(CURSE, "  ---> ");
	wattroff(CURSE, COLOR_PAIR(2));
	ft_exec_pb();
	ft_exec_pb();
	ft_exec_pb();
	ft_exec_pb();
	it = HEAD_A.next;
	x = 17;
	y = parent_y;
	while (it != &HEAD_A)
	{
		(TOP_A == it) ? wattron(CURSE, COLOR_PAIR(5)) : 0;
		mvwprintw(CURSE, (y >> 1) - 3, x, "%d", MOVE(it));
		(TOP_A == it) ? wattroff(CURSE, COLOR_PAIR(5)) : 0;
		refresh();
		wrefresh(CURSE);
		x += 4;
		if (x > (parent_x - 2))
		{
			x = 17;
			y += 2;
		}
		it = it->next;
	}
	x = 2;
	y = parent_y;
	mvwprintw(CURSE, (y >> 1) + 1, x, "Stack B");
	wattron(CURSE, COLOR_PAIR(2));
	wprintw(CURSE, "  ---> ");
	wattroff(CURSE, COLOR_PAIR(2));
	it = HEAD_B.next;
	x = 17;
	while (it != &HEAD_B)
	{
		(TOP_B == it) ? wattron(CURSE, COLOR_PAIR(5)) : 0;
		mvwprintw(CURSE, (y >> 1) + 1, x, "%d", MOVE(it));
		(TOP_B == it) ? wattroff(CURSE, COLOR_PAIR(5)) : 0;
		refresh();
		wrefresh(CURSE);
		x += 4;
		if (x > (parent_x - 2))
		{
			x = 17;
			y += 2;
		}
		it = it->next;
	}
	refresh();
	wrefresh(CURSE);
	sleep(2);
}
