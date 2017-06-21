/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:57:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/12 10:32:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"

# define EXIT_FAIL(x) do {ft_printf("{RED:%s}\n", x); \
								exit(EXIT_FAILURE);} while (0)

#endif
