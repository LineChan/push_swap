/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mailine@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:40:17 by mvillemi          #+#    #+#             */
/*   Updated: 2016/11/12 20:26:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	cursor;

	if (!s)
		return (NULL);
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	cursor = 0;
	i = 0;
	while (s[i])
	{
		if (cursor == 0 && ft_isblank_cr(s[i]))
			i++;
		else
			new[cursor++] = s[i++];
	}
	cursor--;
	while (ft_isblank_cr(new[cursor]))
		new[cursor--] = '\0';
	return (new);
}
