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
	ft_curse_print_instruct();
	wrefresh(SCORE);
	refresh();
	wrefresh(CURSE);
	keypad(stdscr, TRUE);
	//keypad(SCORE, TRUE);
	ft_curse_print_stack();
	sleep(1);
	/*
	while (ch != KEY_LEFT)
		ch = getch();
		*/
	//while (((ch = getch()) != KEY_LEFT) && (ch != KEY_RIGHT));
	return ;
}
