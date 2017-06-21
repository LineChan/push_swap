/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:39:01 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/18 22:07:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	unsigned int	n;

	n = 0;
	new = NULL;
	if (s)
	{
		if (!(new = ft_strnew(ft_strlen((char *)s))))
			return (NULL);
		while (s[n])
		{
			new[n] = f(s[n]);
			n++;
		}
	}
	return (new);
}
