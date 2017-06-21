/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:59:19 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/06 17:45:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *memory;

	if (!(memory = ft_strnew(sizeof(char) * len)) || !s)
		return (NULL);
	ft_strncpy(memory, &s[start], len);
	memory[len] = '\0';
	return (memory);
}
