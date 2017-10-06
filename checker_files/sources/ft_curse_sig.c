/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_sig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:54:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/04 15:54:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** Singletons
*/

t_curse_manager	*ft_curse_sig(void)
{
	static t_curse_manager *p = 0;

	if (0 == p)
		p = (t_curse_manager *)ft_memalloc(sizeof(*p));
	return (p);
}

t_curse_manager	*ft_score_sig(void)
{
	static t_curse_manager *p = 0;

	if (!p)
		p = (t_curse_manager *)ft_memalloc(sizeof(*p));
	return (p);
}

void			ft_curse_del(void)
{
	t_curse_manager	*p;

	p = ft_curse_sig();
	ft_memdel((void **)&p);
}
