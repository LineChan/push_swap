/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:20:43 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/18 21:42:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		n;

	n = 0;
	n = ft_strlen(s);
	if ((char)c == '\0')
		return (&(((char *)s)[n]));
	while (n--)
		if (s[n] == (char)c)
			return (&(((char *)s)[n]));
	return (NULL);
}
