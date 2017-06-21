/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:39:31 by mvillemi          #+#    #+#             */
/*   Updated: 2016/10/17 17:43:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_assert(char const *cond_str, char const *from, int cond)
{
	if (0 == cond)
	{
		ft_printf("ft_assert(%s) failed\n", cond_str);
		ft_printf("  -->> from \"%s\"", from);
		exit(EXIT_FAILURE);
	}
}