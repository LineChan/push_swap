#include "push_swap.h"

/*
** Excute the moves given by push_swap
** Use left or right arrow to navigate
*/
void			ft_curse_do_instruct(void)
{
	int		ch;
	int		i;
	int		starting_nb_move;
	int		parent_x;
	int		parent_y;

	i = 0;
	noecho();
	starting_nb_move = NB_MOVE;
	keypad(stdscr, TRUE);
	TOP_CURSE = &INFO;
	while ((ch = getch()) != 10);
	wclear(CURSE);
	ft_curse_draw_border(CURSE);
	ft_curse_print_instruct();
	ft_curse_print_stack();
	wrefresh(CURSE);
	wrefresh(SCORE);
	while (TOP_CURSE->next != &INFO)
	{
		ch = getch();
		while ((ch != KEY_LEFT) && (ch !=  KEY_RIGHT)
					&& (ch != KEY_F(1)))
			ch = getch();
		if (ch == KEY_F(1))
			return ;
		if (ch == KEY_RIGHT)
		{
			if (i < starting_nb_move)
			{
				++i;
				TOP_CURSE = TOP_CURSE->next;
				ft_check_do_instruct(MOVE(TOP_CURSE));
			}
		}
		else
		{
			--i;
			ft_check_undo_instruct(MOVE(TOP_CURSE));
			TOP_CURSE = TOP_CURSE->prev;
		}
		wclear(CURSE);
		wclear(SCORE);
		mvwprintw(SCORE, 1, 2, "Number of moves : %d / %d", i, starting_nb_move);
		getmaxyx(SCORE, parent_y, parent_x);
		mvwprintw(SCORE, parent_y - 2, parent_x - 27, "Press F1 any time to quit");
		ft_curse_draw_border(CURSE);
		ft_curse_draw_border(SCORE);
		ft_curse_print_instruct();
		ft_curse_print_stack();
		wrefresh(CURSE);
		wrefresh(SCORE);
	}
}
