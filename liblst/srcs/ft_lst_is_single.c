/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_single.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:53:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/10 09:58:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Check if there is a single element in the list
**
** 1st parameter : list to be checked
*/
int					ft_lst_is_single(node lst)
{
	return (!ft_lst_is_head(lst) && lst->next == lst->prev);
}
