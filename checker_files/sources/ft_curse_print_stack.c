/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_print_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:48:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:48:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Prints stacks with ncurse
*/

static void			ft_curse_stack_a(int parent_y, int parent_x)
{
	int		x;
	int		y;
	t_lst	*it;

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
}

static void			ft_curse_stack_b(int parent_y, int parent_x)
{
	t_lst	*it;
	int		y;
	int		x;

	it = HEAD_B.next;
	x = 17;
	y = parent_y;
	while (it != &HEAD_B)
	{
		(TOP_B == it) ? wattron(CURSE, COLOR_PAIR(5)) : 0;
		mvwprintw(CURSE, (y >> 1) + 2, x, "%d", MOVE(it));
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
}

void				ft_curse_print_stack(void)
{
	int		parent_x;
	int		parent_y;
	t_lst	*it;

	getmaxyx(CURSE, parent_y, parent_x);
	mvwprintw(CURSE, (parent_y >> 1) - 3, 2, "Stack A");
	wattron(CURSE, COLOR_PAIR(2));
	wprintw(CURSE, "  ---> ");
	wattroff(CURSE, COLOR_PAIR(2));
	it = HEAD_A.next;
	ft_curse_stack_a(parent_y, parent_x);
	mvwprintw(CURSE, (parent_y >> 1) + 2, 2, "Stack B");
	wattron(CURSE, COLOR_PAIR(2));
	wprintw(CURSE, "  ---> ");
	wattroff(CURSE, COLOR_PAIR(2));
	ft_curse_stack_b(parent_y, parent_x);
	refresh();
	wrefresh(CURSE);
}
