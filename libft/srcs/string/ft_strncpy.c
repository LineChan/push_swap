/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:55:59 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/18 21:10:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	count;

	count = 0;
	while (count < len && src[count])
	{
		dst[count] = src[count];
		count++;
	}
	while (count < len)
		dst[count++] = '\0';
	return (dst);
}
