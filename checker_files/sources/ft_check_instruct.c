/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_instruct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:51:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:53:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Check the instruction given by the push_swap program
** and execute them
*/

void			ft_check_instruct(void)
{
	char	*line;

	while ((line = ft_gnt(0, '\n')) && ft_strcmp("", line))
	{
		if (!ft_check_do_instruct(line))
			EXIT_FAIL("Wrong instruction");
	}
}
