/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:35:40 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/12 20:26:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_power(int unit)
{
	int			power;

	power = 1;
	while (unit-- > 1)
		power *= 10;
	return (power);
}

static int		ft_unit(long int buff)
{
	int			count;

	count = 0;
	if (buff < 0)
		buff = -buff;
	while (buff > 0)
	{
		count++;
		buff /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	long int	buff;
	char		*str;
	int			i;
	int			power;

	buff = n;
	i = 0;
	if (!(str = ft_strnew(sizeof(char) * (ft_unit(buff) + 1))))
		return (NULL);
	if (buff < 0)
	{
		buff *= -1;
		str[i++] = '-';
	}
	else if (buff == 0)
		str[i] = '0';
	power = ft_power(ft_unit(buff));
	while (power)
	{
		str[i++] = buff / power + '0';
		buff %= power;
		power /= 10;
	}
	return (str);
}
