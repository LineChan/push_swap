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
void			ft_print(node it)
{
	if ((it == TOP_A) || (it == TOP_B))
		ft_printf("{YELLOW:%d  }", DATA(it));
	else if (SORTED(it))
		ft_printf("{CYAN:%d  }", DATA(it));
	else
		ft_printf("%d  ", DATA(it));
}

void			ft_print_ab(char const *str)
{
	ft_printf("{RED:%s}\n", str);
	PRINT_A;PRINT_B;
}

void		ft_print_result_list(node it)
{
	ft_printf("%s\n", MOVE(it));
}

void		ft_print_result_ps(void)
{
	ft_lst_foreach(&(push_swap()->lst_info), &ft_print_result_list);
}
