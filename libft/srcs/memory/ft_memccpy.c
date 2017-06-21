/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvilemi <mailine@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 01:14:23 by mvilemi           #+#    #+#             */
/*   Updated: 2016/11/21 13:48:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	ch = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*d = *s;
		if (*s == ch)
			return ((void *)d + 1);
		d++;
		s++;
	}
	return (NULL);
}
