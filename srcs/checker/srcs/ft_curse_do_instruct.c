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
		while (((ch = getch()) != KEY_LEFT) && (ch !=  KEY_RIGHT))
			ch = getch();
		if ((ch == KEY_RIGHT) && (i < starting_nb_move))
		{
			++i;
			TOP_CURSE = TOP_CURSE->next;
			ft_check_do_instruct(MOVE(TOP_CURSE));
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
		ft_curse_draw_border(CURSE);
		ft_curse_draw_border(SCORE);
		ft_curse_print_instruct();
		ft_curse_print_stack();
		wrefresh(CURSE);
		wrefresh(SCORE);
	}
	return ;
	refresh();
	clear();
	TOP_A = TOP_A->next;
	ft_curse_draw_border(CURSE);
	ft_curse_draw_border(SCORE);
	sleep(2);
	getch();
	wrefresh(CURSE);
	wrefresh(SCORE);
#if 0
	while (1)
	{
		while (((ch = getch()) != KEY_LEFT) && (ch !=  KEY_RIGHT))
			ch = getch();
		switch (ch)
		{
			case KEY_LEFT:
				if ((it != &INFO) && (it != INFO.next))
					it = it->prev;
			case KEY_RIGHT:
				if (it != INFO.prev)
					it = it->next;
		}
		if (ch == KEY_F(1))
			break ;
		TOP_CURSE = it;
		ft_curse_print_instruct();
		ft_curse_print_stack();
		wrefresh(CURSE);
		wrefresh(SCORE);
	}
	//while (((ch = getch()) != KEY_LEFT) && (ch != KEY_RIGHT));
		ft_curse_print_instruct();
		ft_curse_print_stack();
		wrefresh(CURSE);
		wrefresh(SCORE);
	#endif
	return ;
}
