/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:04:27 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/06 17:46:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dup;

	if (!(dup = ft_strnew(ft_strlen(s1))))
		return (NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
