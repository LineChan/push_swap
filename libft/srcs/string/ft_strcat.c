/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:29:58 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/18 21:27:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		n;
	int		length_s1;

	n = 0;
	length_s1 = ft_strlen(s1);
	while (s2[n])
	{
		s1[n + length_s1] = s2[n];
		n++;
	}
	s1[n + length_s1] = '\0';
	return (s1);
}
