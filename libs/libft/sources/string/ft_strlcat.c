/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 20:52:03 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/18 21:39:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		len_dest;
	size_t		len_src;
	size_t		limit;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (size + len_src);
	limit = 0;
	dest += len_dest;
	while (*src && (len_dest + limit) < (size - 1))
	{
		*dest++ = *src++;
		limit++;
	}
	if (limit < size)
		*dest = '\0';
	return (len_dest + len_src);
}
