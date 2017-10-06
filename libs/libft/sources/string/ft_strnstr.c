/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 19:19:38 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/20 16:50:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		n;

	i = 0;
	n = ft_strlen(to_find);
	if (*to_find == '\0' && str)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j] && i + j < len)
		{
			if (!(to_find[j + 1]))
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
