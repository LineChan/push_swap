#include "push_swap.h"

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
	ft_printf("nb: %d s : '%c'\n", nb, **s);
	if (!ft_isspace(**s))
	{
		if (**s != 0 ||
				((nb > 2147483647) || ((nb > 2147483648) && (sign == -1))))
			EXIT_FAIL("Error (not an integer)");
	}
	return ((int)nb * sign);
}

static int		ft_is_valid(const char **s)
{
	int			nb;
	node		it;

	nb = ft_push_swap_atoi(s);
	ft_printf("nb valid : {YELLOW:%d}\n", nb);
	ft_printf("NB_ELEM_A : %d\n", NB_ELEM_A);
	if (NB_ELEM_A)
	{
		it = HEAD_A.next;
		while (it != &HEAD_A)
		{
			ft_printf("nb : %d DATA(it) : %d\n", nb, DATA(it));
			if (nb == DATA(it))
					EXIT_FAIL("Error (duplicated elements)");
			it = it->next;
		}
	}
	return (nb);
}

void			ft_exec_parse_push(int nb)
{
	t_stack		*new;

	if (!(new = ft_memalloc(sizeof(t_stack))))
		EXIT_FAIL("Failed memory allocation");
	INIT_LST_HEAD(new->lst);
	new->data = nb;
	new->sorted = 0;
	ft_lst_add_prev(&new->lst, &HEAD_A);
	++NB_ELEM_A;
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
		ft_exec_parse_push(ft_is_valid(&s));
		++i;
		++NB_ELEM;
	}
}

void			ft_exec_parse(int ac, char **av)
{
	int		n;

	n = 0;
	ft_printf("exec parse\n");
	while (n < ac)
	{
		ft_convert_arg(*av);
		++av;
		++n;
	}
}
