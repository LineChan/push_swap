/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:26:30 by mvillemi          #+#    #+#             */
/*   Updated: 2016/12/05 17:37:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	start;
	size_t	end;
	size_t	j;
	size_t	i;

	array = NULL;
	j = 0;
	i = 0;
	if (!s || !(array = (char **)ft_memalloc(sizeof(char *) *
					(ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[j] && i < ft_count_word(s, c))
	{
		end = 0;
		while (s[j] == c)
			j++;
		start = j;
		while (s[j++] != c)
			end++;
		if (!(array[i++] = ft_strsub(s, start, end)))
			return (NULL);
	}
	array[ft_count_word(s, c)] = 0;
	return (array);
}
