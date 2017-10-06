/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:52:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:56:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Checker with visualization
*/

static void			ft_curse_set_color(void)
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

static void			ft_curse_intro(void)
{
	int		parent_y;
	int		parent_x;

	getmaxyx(stdscr, parent_y, parent_x);
	ft_curse_draw_border(CURSE);
	ft_curse_draw_border(SCORE);
	refresh();
	mvwprintw(CURSE, ((parent_y - SCORE_SIZE) >> 1) >> 1,
		((parent_x - 40) >> 1), "Use left or right arrow to do/undo moves");
	mvwprintw(CURSE, (parent_y - SCORE_SIZE) >> 1, (parent_x >> 1) - 14,
		"Press enter to start sorting");
	mvwprintw(SCORE, parent_y, 2, "Number of moves : 0 / %d\n", NB_MOVE);
	refresh();
	wrefresh(CURSE);
	wrefresh(SCORE);
}

static void			ft_curse_display(void)
{
	ft_curse_set_color();
	ft_curse_draw_border(CURSE);
	ft_curse_draw_border(SCORE);
	refresh();
	wrefresh(CURSE);
	wrefresh(SCORE);
	ft_curse_intro();
	noecho();
	keypad(stdscr, TRUE);
	TOP_CURSE = &INFO;
	while (getch() != 10)
		;
	wclear(CURSE);
	ft_curse_wait_instruct();
}

void				ft_curse_instruct(void)
{
	int			parent_x;
	int			parent_y;
	char		*line;

	while ((line = ft_fgnt("result.txt", '\n'))
				&& ft_strcmp("", line))
		ft_exec_add_move(line);
	initscr();
	cbreak();
	curs_set(FALSE);
	getmaxyx(stdscr, parent_y, parent_x);
	CURSE = newwin(parent_y - SCORE_SIZE, parent_x, 0, 0);
	SCORE = newwin(SCORE_SIZE, parent_x, parent_y - SCORE_SIZE, 0);
	keypad(CURSE, 1);
	keypad(SCORE, 1);
	ft_curse_display();
	delwin(CURSE);
	delwin(SCORE);
	endwin();
}
