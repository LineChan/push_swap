/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:46:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 23:49:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ft_exec.h"

/*
** Bonus : visual with NCURSES
*/
# include "curses.h"
# define CURSE_MODE		(ft_curse_sig()->ncurse_mode)
# define CURSE			(ft_curse_sig()->win)
# define SCORE			(ft_score_sig()->win)
# define SCORE_SIZE		10

/*
** Check protoypes
*/
void					ft_check_instruct(void);
int						ft_check_do_instruct(const char *line);
int						ft_check_undo_instruct(const char *line);

/*
** Curses
*/
typedef struct			s_curse_manager
{
	int			ncurse_mode;
	WINDOW		*win;
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
