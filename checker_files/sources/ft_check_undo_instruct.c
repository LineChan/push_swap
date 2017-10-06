/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_undo_instruct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:51:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:51:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Undo a move
**
** 1st parameter : move to undo
*/

int				ft_check_undo_instruct(char const *line)
{
	if (!ft_strcmp("pa", line))
		ft_exec_pb();
	else if (!ft_strcmp("pb", line))
		ft_exec_pa();
	else if (!ft_strcmp("ra", line))
		ft_exec_rra();
	else if (!ft_strcmp("rb", line))
		ft_exec_rrb();
	else if (!ft_strcmp("rr", line))
		ft_exec_rrr();
	else if (!ft_strcmp("rra", line))
		ft_exec_ra();
	else if (!ft_strcmp("rrb", line))
		ft_exec_rb();
	else if (!ft_strcmp("rrr", line))
		ft_exec_rr();
	else
		return (0);
	return (1);
}
