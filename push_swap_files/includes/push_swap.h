/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:46:23 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 23:52:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_exec.h"

void					ft_handle_option(int *ac, char ***av, int option[]);

/*
** Push Swap prototypes
*/
void					ft_ps_sort(void);
void					ft_ps_sort_three(void);
void					ft_ps_sort_seven(void);
void					ft_ps_select_sort(void);
void					ft_ps_quick_sort(void);
void					ft_ps_quick_a(void);
void					ft_ps_quick_b(void);
void					ft_quick_select(int *push, int *pivot);
void					ft_ps_clean_result(void);
void					ft_ps_find_shortest_path(const t_lst *head,
													const int ref);
void					ft_ps_find_where_to_push(const t_lst *head,
													const int ref);
void					ft_ps_push_max(const t_lst *head, const int len);
int						ft_ps_count_step(const t_lst *head, int ref);
int						ft_ps_head_is_reverse_sorted(const t_lst *head);

#endif
