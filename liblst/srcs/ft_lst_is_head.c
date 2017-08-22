/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_is_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 09:58:57 by mvillemi          #+#    #+#             */
/*   Updated: 2017/08/22 13:10:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"

/*
** Check if the list is empty (only the head is allocated)
**
** 1st parameter : list to be checked
*/
int					ft_lst_is_head(t_lst *lst)
{
	return (lst->next == lst || lst->prev == lst);
}
