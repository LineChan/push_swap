/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:08:39 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/19 10:58:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE (40000)

typedef struct			s_gnl
{
	int				fd;
	char			*save;
	struct s_gnl	*next;
}					t_gnl;

int				get_next_line(const int fd, char **line);

#endif
