/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_wait_instruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:52:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:52:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Visualization set up
*/

void			ft_curse_wait_instruct(void)
{
	int		ch;
	int		starting_nb_move;
	int		parent_x;
	int		parent_y;

	starting_nb_move = NB_MOVE;
	ft_curse_draw_border(CURSE);
	ft_curse_print_instruct();
	ft_curse_print_stack();
	wrefresh(CURSE);
	wrefresh(SCORE);
	while ((ch = getch()) != KEY_F(1))
	{
		mvwprintw(SCORE, 1, 2, "Number of moves : %d / %d",
					ft_curse_select_instruct(&ch, starting_nb_move),
					starting_nb_move);
		getmaxyx(SCORE, parent_y, parent_x);
		mvwprintw(SCORE, parent_y - 2, parent_x - 27, "Press F1 to quit");
		ft_curse_draw_border(CURSE);
		ft_curse_draw_border(SCORE);
		ft_curse_print_instruct();
		ft_curse_print_stack();
		wrefresh(CURSE);
		wrefresh(SCORE);
	}
}
