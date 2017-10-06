/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:27:48 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/21 13:41:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	if (!(to_find[0]))
		return ((char *)str);
	while (*str)
	{
		if (ft_strnequ(str, to_find, ft_strlen(to_find)))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
