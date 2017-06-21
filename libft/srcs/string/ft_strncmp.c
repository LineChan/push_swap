/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:20:55 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/12 20:20:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t j;

	j = 0;
	while (j < n)
	{
		if (s1[j] == s2[j] && s1[j])
			j++;
		else
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	}
	return (0);
}
