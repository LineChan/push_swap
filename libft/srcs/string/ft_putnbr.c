/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:21:35 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/06 19:30:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int buff;

	buff = (long int)nb;
	if (buff < 0)
	{
		ft_putchar('-');
		buff = -buff;
	}
	if (buff < 10)
		ft_putchar(buff % 10 + '0');
	else
	{
		ft_putnbr(buff / 10);
		ft_putchar(buff % 10 + '0');
	}
}
