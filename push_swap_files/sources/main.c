/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:09:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/10 20:36:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort parameters in increasing order
*/

int					main(int ac, char **av)
{
	int		option[2];

	option[0] = 0;
	option[1] = 0;
	if (ac == 1)
		EXIT_FAIL("");
	ft_handle_option(&ac, &av, option);
	ft_exec_parse(&ac, av);
	ft_ps_sort();
	if (option[0])
		ft_ps_clean_result();
	if (option[1])
		ft_print_result_ps();
	else
		ft_lst_foreach(&INFO, &ft_print_result_list);
	ft_del_singl();
	return (0);
}
