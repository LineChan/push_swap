/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:09:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 18:01:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort parameters in increasing order
*/

void				ft_handle_
int					main(int ac, char **av)
{
#if 1
	int		option[2];

	option[0] = 0;
	option[1] = 0;
	if (ac == 1)
		EXIT_FAIL("");
	++av;
	--ac;
	ft_handle_option_test(&ac, av, option);
	option
#endif

#if 0
	int		clean;
	int		x;

	if (ac == 1)
		EXIT_FAIL("");
	++av;
	--ac;
	clean = 0;
	x = 0;
	if (!ft_strcmp("--clean", *av))
	{
		--ac;
		++av;
		if (ac < 2)
			EXIT_FAIL("Error (no argument)");
		else
		++clean;
	}
	if (!ft_strcmp("-x", *av))
	{
		--ac;
		++av;
		if (!ac)
			EXIT_FAIL("Error (no argument)");
		else
			x = 1;
	}
#endif
	ft_printf("av[0] : %s\n", *av);
	ft_exec_parse(&ac, av);
	ft_ps_sort();
	if (option[0])
		ft_ps_clean_result();
	if (option[1])
		ft_print_result_ps();
	else
		ft_lst_foreach(&INFO, &ft_print_result_list);
	return (0);
}
