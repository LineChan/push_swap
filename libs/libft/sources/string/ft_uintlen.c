/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 03:41:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/02/21 18:40:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_uintlen(unsigned long int nb, unsigned long int base)
{
	int len;

	len = 0;
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	return (++len);
}
