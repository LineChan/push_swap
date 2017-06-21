/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:43:33 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/06 17:43:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	new = NULL;
	if (s)
	{
		if (!(new = ft_strnew(ft_strlen((char *)s))))
			return (NULL);
		while (s[i])
		{
			new[i] = f(i, s[i]);
			i++;
		}
	}
	return (new);
}
