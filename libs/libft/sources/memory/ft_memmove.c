/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:03:06 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/18 21:03:32 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	char	*d;

	tmp = (char *)src;
	d = (char *)dst;
	if (dst < src && dst)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			*(d + len) = *(tmp + len);
	return (dst);
}
