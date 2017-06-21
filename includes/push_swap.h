/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:35:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/22 14:27:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../liblst/includes/liblst.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/debug.h"

/*
** Define
*/
# define C_STACK(it)	CONTAINEROF(it, t_stack, lst)
# define DATA(it)		(C_STACK(it)->data)
# define SORTED(it)		(C_STACK(it)->sorted)

# define C_PS(it)		CONTAINEROF(it, t_result, lst)
# define MOVE(it)		(C_PS(it)->move)

# define NB_MOVE		(push_swap()->nb_move)
# define NB_MOVE_SAVE	(push_swap_save()->nb_move)
# define NB_ELEM		(push_swap()->nb_elem)
# define NB_ELEM_A		(stack_a()->nb_elem)
# define NB_ELEM_B		(stack_b()->nb_elem)

# define HEAD_A			(stack_a()->lst_head)
# define HEAD_B			(stack_b()->lst_head)
# define INFO			(push_swap()->lst_info)
# define INFO_SAVE		(push_swap_save()->lst_info)

# define TOP_A			(stack_a()->top)
# define TOP_B			(stack_b()->top)

# define PRINT_A														\
	do {																\
		ft_printf("Stack A  \t{GREEN:-------->}    ");	\
		ft_lst_foreach(&HEAD_A, &ft_print); 							\
		ft_printf("\n"); 									\
	} while (0)

# define PRINT_B														\
	do {																\
		ft_printf("Stack B  \t{GREEN:-------->}    ");	\
		ft_lst_foreach(&HEAD_B, &ft_print); 							\
		ft_printf("\n");									\
	} while (0)

# define PRINT_AB(x)	ft_print_ab(x)

/*
** Structure
*/
typedef struct		s_stack
{
	int			data;
	int			sorted;
	t_lst		lst;
}					t_stack;

typedef struct		s_head
{
	int			nb_elem;
	int			nb_move;
	node		top;
	t_lst		lst_head;
}					t_head;

typedef struct		s_info
{
	int			nb_move;
	int			nb_elem;
	t_lst		lst_info;
}					t_info;

typedef struct		s_result
{
	char		*move;
	t_lst		lst;
}					t_result;
/*
** Singletons
*/
//int			*nb_elem(void);

int			*clean(void);
t_info		*push_swap(void);
t_info		*push_swap_save(void);
t_head		*stack_a(void);
t_head		*stack_b(void);

/*
** Check protoypes
*/


/*
** Exec prototypes
*/
void		ft_exec_parse(int ac, char **av, int **array);


//


void		ft_exec_init(void);
void		ft_exec_setup(int **array);
void		ft_exec_push(int **array, int count);
void		ft_exec_add_move(char const *move);
void		ft_del_move(t_result **ptr);
void		ft_print(node head);

void		ft_exec_ra(void);
void		ft_exec_rb(void);
void		ft_exec_rr(void);
void		ft_exec_pa(void);
void		ft_exec_pb(void);
void		ft_exec_sa(void);
void		ft_exec_sb(void);
void		ft_exec_ss(void);
void		ft_exec_rra(void);
void		ft_exec_rrb(void);
void		ft_exec_rrr(void);

void		ft_print_ab(char const *str);
void		ft_print_result_ps(int _bool);

int			ft_exec_head_is_sorted(node head);
/*
** Push Swap prototypes
*/
void		ft_ps_sort(int **array);
void		ft_ps_find_shortest_path(node head, int ref);
void		ft_ps_find_where_to_push(node head, int ref);

void		ft_ps_sort_three(void);
void		ft_ps_sort_seven(void);
void		ft_ps_select_sort(node head);
void		ft_ps_reverse_sort(node head);
void		ft_ps_merge_sort_tmp(node head);
void		ft_ps_merge_sort(void);
void		ft_ps_quick_sort(void);
void		ft_quick_b(void);
void		ft_quick_a(void);
void		ft_quick_select(int *push, int *pivot);
void		ft_ps_clean_result(void);

int			ft_ps_is_reverse_sorted(node head);
int			ft_ps_head_is_reverse_sorted(node head);
int			ft_ps_count_step(node head, int ref);





int			ft_is_left(node *left, int *pitch, node *pivot);
void		ft_ps_push_max(node head, int len); // quicksort



typedef struct			s_checker_exec
{
	char const			*input;
	void				(*func)(void);
}						t_checker_exec;

/*
**	ncurses
*/

# include "curses.h"
# include "ncurses.h"
typedef struct			s_curse_manager
{
	int 				ncurse_mode;
	WINDOW				*win;
}						t_curse_manager;

#define CURSE_MODE		ft_curse_sig()->ncurse_mode
#define CURSE			ft_curse_sig()->win
//#define CURSE(member)	ft_curse_sig()->member
#define SCORE			ft_score_sig()->win
//#define SCORE(member)	ft_score_sig()->member
# define PRINTW_A						\
	do {											\
		ft_curse_display(CURSE, "Stack A\t");		\
		ft_lst_foreach(&HEAD_A, &ft_mvprint);		\
	} while (0)										\

# define PRINTW_B								\
	do {											\
		ft_curse_display(CURSE, "Stack B\t");		\
		ft_lst_foreach(&HEAD_B, &ft_mvprint);		\
	} while (0)										\

int			ft_exec_instruct(char const *line);
void					ft_curse_init(void);
void					ft_mvprint(node it);
void					ft_curse_display(WINDOW *win, char const *message);
t_curse_manager			*ft_curse_sig(void);
t_curse_manager			*ft_score_sig(void);
void					ft_del_sig(void);
int						ft_curse_read_instruction(void);

#endif
