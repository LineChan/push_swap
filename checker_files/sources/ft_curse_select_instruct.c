/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_select_instruct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:52:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:54:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Wait for left or right input and execute the corresponding instruction
** 1st parameter : input value
** 2nd parameter : number of instructions
*/

int					ft_curse_select_instruct(int *ch,
											const int starting_nb_move)
{
	static int			i = 0;

	while ((*ch != KEY_LEFT) && (*ch != KEY_RIGHT))
		*ch = getch();
	if (*ch == KEY_RIGHT)
	{
		if (i < starting_nb_move)
		{
			++i;
			TOP_CURSE = TOP_CURSE->next;
			ft_check_do_instruct(MOVE(TOP_CURSE));
		}
	}
	else if (i > 0)
	{
		--i;
		ft_check_undo_instruct(MOVE(TOP_CURSE));
		TOP_CURSE = TOP_CURSE->prev;
	}
	wclear(CURSE);
	wclear(SCORE);
	return (i);
}
