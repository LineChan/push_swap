/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:01:02 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 23:17:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

/*
** Check arguments for : duplicated elements, integer limits, non
** numerical characters
**
** 1st parameter : number of arguments
** 2nd parameter : arguments container
*/

static int		ft_push_swap_atoi(const char **s)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while (ft_isspace(**s))
		++*s;
	if (**s == '-')
		sign = -1;
	if ((**s == '-') || (**s == '+'))
		++(*s);
	if (!ft_isdigit(**s))
		EXIT_FAIL("Error (not a number)");
	while (ft_isdigit(**s))
		nb = (nb << 3) + (nb << 1) + *(*s)++ - 48;
	if (!ft_isspace(**s))
	{
		if (**s != 0 ||
				((nb > 2147483647) || ((nb > 2147483648) && (sign == -1))))
			EXIT_FAIL("Error (not an integer)");
	}
	return ((-1 == sign) ? (int)-nb : (int)nb);
}

static int		ft_valid_number(const char **s)
{
	int			nb;
	t_lst		*it;

	nb = ft_push_swap_atoi(s);
	if (NB_ELEM_A)
	{
		it = HEAD_A.next;
		while (it != &HEAD_A)
		{
			if (nb == DATA(it))
				EXIT_FAIL("Error (duplicated elements)");
			it = it->next;
		}
	}
	return (nb);
}

static void		ft_convert_arg(const char *s)
{
	int		word;
	int		i;

	i = 0;
	word = ft_count_word(s, ' ');
	if (!ft_strlen(s) || !word)
		EXIT_FAIL("Error (null or empty string");
	while (i < word)
	{
		ft_exec_push(ft_valid_number(&s));
		++i;
	}
}

void			ft_exec_parse(int *ac, char **av)
{
	while (*ac)
	{
		ft_convert_arg(*av);
		++av;
		--*ac;
	}
}
