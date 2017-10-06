/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 13:29:36 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/04 10:49:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy the string src to dst
** Return a pointer to the terminating '\0' character of dst
**
** 1st parameter : destination string
** 2nd parameter : source string
*/

char				*ft_stpcpy(char *dst, const char *src)
{
	size_t	len;

	len = ft_strlen(src);
	return ((char *)ft_memcpy(dst, src, len + 1) + len);
}
