/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_singl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:05:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/10 20:16:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Free all allocated structures
*/

static void			ft_del_move(t_lst *src)
{
	t_result	*ptr;

	ptr = C_PS(src);
	if (!ptr)
		return ;
	ft_memdel((void **)&ptr);
}

static void			ft_del_push_swap(void)
{
	t_info		*ptr;

	ptr = push_swap();
	if (!ft_lst_is_head(&INFO))
		ft_lst_foreach(&(ptr->lst_info), &ft_del_move);
	ft_memdel((void **)&ptr);
}

static void			ft_del_stack(t_lst *src)
{
	t_stack		*ptr;

	ptr = C_STACK(src);
	if (!ptr)
		return ;
	ft_lst_del(src);
	ft_memdel((void **)&ptr);
}

static void			ft_del_stack_a(void)
{
	t_head		*ptr;

	ptr = stack_a();
	if (!ft_lst_is_head(&HEAD_A))
		ft_lst_foreach(&(ptr->lst_head), &ft_del_stack);
	ft_memdel((void **)&ptr);
}

static void			ft_del_stack_b(void)
{
	t_head		*ptr;

	ptr = stack_b();
	ft_memdel((void **)&ptr);
}

void				ft_del_singl(void)
{
	ft_del_push_swap();
	ft_del_stack_a();
	ft_del_stack_b();
}
