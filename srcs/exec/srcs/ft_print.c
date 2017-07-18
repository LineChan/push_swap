/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:53:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/09 11:24:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Print functions
*/
void		ft_print_result_list(const node it)
{
	PRINTF("%s\n", MOVE(it));
}

void		ft_print_result_ps(void)
{
	int		fd;
	node	it;

	it = INFO.next;
	fd = open("result.txt", O_TRUNC | O_RDWR);
	if (IS_NEG(fd))
		EXIT_FAIL("File descriptor not open");
	while (it != &INFO)
	{
		write(fd, MOVE(it), ft_strlen(MOVE(it)));
		write(fd, "\n", 1);
		it = it->next;
	}
	close(fd);
}
