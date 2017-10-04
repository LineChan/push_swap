#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../liblst/includes/liblst.h"
# include "../libft/includes/libft.h"

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

# define CASE_A (IS_NEG((DATA(TOP_A->next) - DATA(TOP_A))))
# define CASE_B (IS_NEG((DATA(TOP_A->next->next) - DATA(TOP_A->next))))
# define CASE_C (IS_NEG((DATA(TOP_A) - DATA(TOP_A->next->next))))
# define CASE_1 (CASE_A && !CASE_B)
# define CASE_2 (CASE_C && CASE_B)
# define CASE_3 (!CASE_A && !CASE_C)

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
	t_lst		*top;
	t_lst		lst_head;
}					t_head;

typedef struct		s_info
{
	int			nb_move;
	t_lst		*top_curse;
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
t_info		*push_swap(void);
t_head		*stack_a(void);
t_head		*stack_b(void);

void		ft_handle_option(int *ac, char **av, int option[]);

/*
** Check protoypes
*/
void		ft_check_instruct(void);
int			ft_check_do_instruct(const char *line);
int			ft_check_undo_instruct(const char *line);

/*
** Exec prototypes
*/
void		ft_exec_parse(int *ac, char **av);
void		ft_exec_push(const int nb);
void		ft_exec_add_move(const char *move);
int			ft_exec_head_is_sorted(void);

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

void		ft_print_result_ps(void);
void		ft_print_result_list(t_lst *it);

/*
** Push Swap prototypes
*/
void		ft_ps_sort(void);
void		ft_ps_sort_three(void);
void		ft_ps_sort_seven(void);
void		ft_ps_select_sort(void);
void		ft_ps_quick_sort(void);
void		ft_ps_quick_a(void);
void		ft_ps_quick_b(void);
void		ft_quick_select(int *push, int *pivot);
void		ft_ps_clean_result(void);
void		ft_ps_find_shortest_path(const t_lst *head, const int ref);
void		ft_ps_find_where_to_push(const t_lst *head, const int ref);
void		ft_ps_push_max(const t_lst *head, const int len);
int			ft_ps_count_step(const t_lst *head, int ref);
int			ft_ps_head_is_reverse_sorted(const t_lst *head);

/*
** Curses
*/
# include "curses.h"
# define CURSE_MODE		(ft_curse_sig()->ncurse_mode)
# define CURSE			(ft_curse_sig()->win)
# define SCORE			(ft_score_sig()->win)
# define SCORE_SIZE		10

typedef struct			s_curse_manager
{
	int 				ncurse_mode;
	WINDOW				*win;
}						t_curse_manager;

t_curse_manager			*ft_curse_sig(void);
t_curse_manager			*ft_score_sig(void);

void					ft_curse_del(void);
void					ft_curse_instruct(void);
void					ft_curse_wait_instruct(void);
void					ft_curse_do_instruct(void);
void					ft_curse_print_instruct(void);
void					ft_curse_print_stack(void);
void					ft_curse_draw_border(WINDOW *screen);

int						ft_curse_select_instruct(int *ch, const int nb_move);
#endif
