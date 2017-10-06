/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:53:12 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/05 15:47:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Print functions
*/

void		ft_print_result_list(t_lst *it)
{
	ft_printf("%s\n", MOVE(it));
}

void		ft_print_result_ps(void)
{
	int		fd;
	t_lst	*it;

	it = INFO.next;
	fd = open("result.txt", O_CREAT | O_TRUNC | O_RDWR, 0666);
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
