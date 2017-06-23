#include "push_swap.h"

/*
** Checker with visualization (ncurse lib)
*/
static void		ft_curse_set_color(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
}

/*
void			ft_curse_get_input(void)
{
	char	input[5];
	//int ch;

	//ch = getch();
	noecho();
	ft_memset((void *)input, '\0', 5);
	//while( getstr(input))
	getstr(input);
	while (*input)
	{
		mvwprintw(CURSE, 1, 1, "Reading input ... %s", input);
		refresh();
		wrefresh(CURSE);
		sleep(1);
		ft_memset((void *)input, '\0', 5);
		getstr(input);
		wclear(CURSE);
		ft_curse_draw_border(CURSE);
		ft_exec_add_move(input);
	}
}
*/
void			ft_curse_intro(int parent_y,
								int parent_x,
								int score_size)
{
	ft_curse_draw_border(CURSE);
	ft_curse_draw_border(SCORE);
	refresh();
mvwprintw(CURSE, (parent_y - score_size) >> 1, (parent_x >> 1) - 14, "Press enter to start sorting");
	mvwprintw(SCORE, 1, 2, "Number of moves : %d\n", NB_MOVE);
	refresh();
	wrefresh(CURSE);
	wrefresh(SCORE);
	sleep(1);
	return ;
mvwprintw(CURSE, parent_y, (parent_x >> 1) - 11, "Press enter to start sorting");
}

void			ft_curse_instruct(void)
{
	int			score_size;
	int			parent_x;
	int			parent_y;
	int			fd;
	char		*line;

	fd = open("result.txt", O_RDONLY);
	if (IS_NEG(fd))
		EXIT_FAIL("File not open");

	while (get_next_line(fd, &line) && ft_strcmp("", line))
	{
		ft_exec_add_move(line);
	}
	score_size = 10;
	initscr();
	cbreak();
	curs_set(FALSE);
	getmaxyx(stdscr, parent_y, parent_x);
	CURSE = newwin(parent_y - score_size, parent_x, 0, 0);
	SCORE = newwin(score_size, parent_x, parent_y - score_size, 0);
	keypad(CURSE, 1);
	keypad(SCORE, 1);
	ft_curse_set_color();
	ft_curse_draw_border(CURSE);
	ft_curse_draw_border(SCORE);
	refresh();
	wrefresh(CURSE);
	wrefresh(SCORE);
	ft_curse_intro(parent_y, parent_x, score_size);
	ft_curse_do_instruct();
	//ft_curse_get_input();
	getch();
	delwin(CURSE);
	delwin(SCORE);
	endwin();
}
