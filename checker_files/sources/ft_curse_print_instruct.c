/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_print_instruct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:52:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:52:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Print all the moves in the score screen
*/

void			ft_curse_print_instruct(void)
{
	int		parent_x;

	getmaxyx(SCORE, parent_x, parent_x);
	if ((TOP_CURSE->prev != &INFO) && (TOP_CURSE != &INFO))
	{
		mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) - 20,
				"%s  ", MOVE(TOP_CURSE->prev));
	}
	wattron(SCORE, COLOR_PAIR(2));
	mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) - 6, "<---- ");
	wattroff(SCORE, COLOR_PAIR(2));
	if (TOP_CURSE == &INFO)
		mvwprintw(SCORE, (SCORE_SIZE >> 1), (parent_x >> 1), "start");
	else
		mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) + 2,
				"%s  ", MOVE(TOP_CURSE));
	wattron(SCORE, COLOR_PAIR(2));
	mvwprintw(SCORE, SCORE_SIZE >> 1, (parent_x >> 1) + 10, " ---->");
	wattroff(SCORE, COLOR_PAIR(2));
	if (TOP_CURSE != INFO.prev)
		wprintw(SCORE, "  %s", MOVE(TOP_CURSE->next));
	return ;
}
