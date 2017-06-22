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

static void		ft_curse_draw_border(WINDOW *screen)
{
	int		x;
	int		y;
	int		i;

	getmaxyx(screen, y, x);
	mvwprintw(screen, 0, 0, "+");
	mvwprintw(screen, y - 1, 0, "+");
	mvwprintw(screen, 0, x - 1, "+");
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

void			ft_curse_get_input(void)
{
	int ch = getch();
	mvwprintw(CURSE, 1, 1, "ch : %d\n", ch);
	ft_curse_draw_border(CURSE);
	refresh();
	wrefresh(CURSE);
	sleep(2);
	return ;
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

/*
#include <errno.h>
#include <string.h>
void flushSTDIN() {
	int c;
	do { 
		errno = 0;
		c = getchar();

		if (errno) { 
			fprintf(stderr, "Error flushing standard input buffer: %s\n", strerror(errno)); 
		} 
	}
	while ((c != '\n') && (!feof(stdin)));

	return; 
}
*/

void			ft_curse_instruct(void)
{
	int		score_size;
	int		parent_x;
	int		parent_y;

	/*
	char		*line;

	while (get_next_line(0, &line) && ft_strcmp("", line))
	{
		ft_exec_add_move(line);
	}
	*/
	//flushSTDIN();
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
	ft_curse_get_input();
	sleep(3);
	getch();
	delwin(CURSE);
	delwin(SCORE);
	endwin();
	return ;




	ft_print_result_ps();
	cbreak();
	//fseek(stdin,0,SEEK_END);
	CURSE = newwin(parent_y - score_size, parent_x, 0, 0);
	clear();
	keypad(CURSE, 1);
	ft_curse_set_color();
	ft_curse_draw_border(CURSE);
	refresh();
	wrefresh(CURSE);
	sleep(3);
	endwin();
	//char test[10];
	keypad(CURSE, 1);
	int ch;
	nodelay(CURSE, TRUE);
	for (;;) {
		if ((ch = getch()) == ERR)
		{
			mvwprintw(CURSE, 1, 1, "Reading test ... %d", ch);
			refresh();
			wrefresh(CURSE);
			sleep(3);
			clear();
		}
		else
		{
			mvwprintw(CURSE, 1, 1, "Reading not ERR ... %d", ch);
			refresh();
			wrefresh(CURSE);
			sleep(3);
			clear();
		}
	}
return ;
	ch = getch();
	mvwprintw(CURSE, 1, 1, "Reading test ... %d", ch);
	refresh();
	wrefresh(CURSE);
	sleep(3);


}
