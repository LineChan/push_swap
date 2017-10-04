/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:42:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 18:01:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Handle options
**
** 1st parameter : number of arguments
** 2nd parameter : list of arguments
** 3rd parameter : option
*/

void		ft_handle_option(int *ac, char **av, int option[])
{
	if (!ft_strcmp("--clean", *av))
	{
		--*ac;
		++av;
		ft_printf("option av : %s\n", *av);
		if (*ac < 2)
			EXIT_FAIL("ERROR : no argument");
		else
			++option[0];
	}
	if (!ft_strcmp("-x", *av))
	{
		--*ac;
		++av;
		if (!*ac)
			EXIT_FAIL("ERROR : no arugment");
		else
			++option[1];
	}
}
