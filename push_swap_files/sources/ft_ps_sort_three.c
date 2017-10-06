/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:58:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/05 14:40:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort a list with 3 elemets
*/

void			ft_ps_sort_three(void)
{
	if (CASE_1)
	{
		if (CASE_C)
			ft_exec_sa();
		else
			ft_exec_ra();
	}
	else if (CASE_2)
	{
		ft_exec_rra();
		ft_exec_sa();
	}
	else if (CASE_3)
		ft_exec_rra();
	else if (ft_ps_head_is_reverse_sorted(&HEAD_A))
	{
		ft_exec_ra();
		ft_exec_sa();
	}
	ft_lst_moveto_prev(&HEAD_A, TOP_A);
}
