/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:28:47 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/06 19:28:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int buff;

	buff = n;
	if (buff < 0)
	{
		ft_putchar_fd('-', fd);
		buff = -buff;
	}
	if (buff < 10)
		ft_putchar_fd(buff % 10 + '0', fd);
	else
	{
		ft_putnbr_fd(buff / 10, fd);
		ft_putchar_fd(buff % 10 + '0', fd);
	}
}
