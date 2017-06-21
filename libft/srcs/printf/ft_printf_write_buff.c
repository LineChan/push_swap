/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write_buff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:34:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:08:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Write buffer, set the written char to '\0',
** re init the pointer to the beginning, return ret
*/

void			ft_printf_write_buff(t_struct *arg)
{
	*ret() += write(arg->fd, arg->buff, SIZE);
	ft_memset((void *)arg->buff, '\0', SIZE);
	arg->p = arg->buff;
}
