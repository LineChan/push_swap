/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 23:27:49 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/13 10:06:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
** Main function
*/

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	t_struct	arg;

	va_start(arg.ap, s);
	*ret() = 0;
	ft_memset((void *)arg.buff, '\0', BUFF_MAX + 1);
	arg.p = arg.buff;
	ft_printf_parsing((char *)s, &arg);
	va_end(ap);
	return (*ret());
}
