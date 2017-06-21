/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 01:38:56 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:07:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Initializing all t_struct arg parameters
*/

void		ft_printf_init_struct(t_struct *arg)
{
	arg->type ^= arg->type;
	arg->rdm ^= arg->rdm;
	arg->padd ^= arg->padd;
	arg->dot ^= arg->dot;
	arg->neg ^= arg->neg;
	arg->flag ^= arg->flag;
}
