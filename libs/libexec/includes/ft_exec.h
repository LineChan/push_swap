/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:46:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/10 18:06:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "libft.h"
# include "liblst.h"

/*
** For open
*/
# include <fcntl.h>

/*
** Define
*/
# define C_STACK(it)	CONTAINEROF(it, t_stack, lst)
# define DATA(it)		(C_STACK(it)->data)
# define SORTED(it)		(C_STACK(it)->sorted)

# define C_PS(it)		CONTAINEROF(it, t_result, lst)
# define MOVE(it)		(C_PS(it)->move)
# define NEXT(i, a, b)	(!ft_strcmp(MOVE(i), a) && !ft_strcmp(MOVE(i->next), b))

# define NB_MOVE		(push_swap()->nb_move)
# define NB_ELEM_A		(stack_a()->nb_elem)
# define NB_ELEM_B		(stack_b()->nb_elem)

# define HEAD_A			(stack_a()->lst_head)
# define HEAD_B			(stack_b()->lst_head)
# define INFO			(push_swap()->lst_info)

# define TOP_A			(stack_a()->top)
# define TOP_B			(stack_b()->top)
# define TOP_CURSE		(push_swap()->top_curse)

# define CASE_A			(IS_NEG((DATA(TOP_A->next) - DATA(TOP_A))))
# define CASE_B			(IS_NEG((DATA(TOP_A->next->next) - DATA(TOP_A->next))))
# define CASE_C			(IS_NEG((DATA(TOP_A) - DATA(TOP_A->next->next))))
# define CASE_1			(CASE_A && !CASE_B)
# define CASE_2			(CASE_C && CASE_B)
# define CASE_3			(!CASE_A && !CASE_C)

/*
** Structure
*/
typedef struct			s_stack
{
	int			data;
	int			sorted;
	t_lst		lst;
}						t_stack;

typedef struct			s_head
{
	int			nb_elem;
	int			nb_move;
	t_lst		*top;
	t_lst		lst_head;
}						t_head;

typedef struct			s_info
{
	int			nb_move;
	t_lst		*top_curse;
	t_lst		lst_info;
}						t_info;

typedef struct			s_result
{
	char		move[4];
	t_lst		lst;
}						t_result;

/*
** Singletons
*/
t_info					*push_swap(void);
t_head					*stack_a(void);
t_head					*stack_b(void);

void					ft_handle_option(int *ac, char ***av, int option[]);
void					ft_del_singl(void);

/*
** Exec prototypes
*/
void					ft_exec_parse(int *ac, char **av);
void					ft_exec_push(const int nb);
void					ft_exec_add_move(const char *move);
int						ft_exec_head_is_sorted(void);

void					ft_exec_ra(void);
void					ft_exec_rb(void);
void					ft_exec_rr(void);
void					ft_exec_pa(void);
void					ft_exec_pb(void);
void					ft_exec_sa(void);
void					ft_exec_sb(void);
void					ft_exec_ss(void);
void					ft_exec_rra(void);
void					ft_exec_rrb(void);
void					ft_exec_rrr(void);

void					ft_print_result_ps(void);
void					ft_print_result_list(t_lst *it);

#endif
