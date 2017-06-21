/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_tlst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 10:12:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/06 14:35:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H
# include <stdint.h>

/*
** Libft
*/
#include "../../libft/includes/libft.h"

/*
** Linux like circular doubly linked list
**
** Explanations found here : 
**		https://0xax.gitbooks.io/linux-insides/content/DataStructures/dlist.html
** Source : 
**		https://github.com/torvalds/linux/blob/master/include/linux/list.h
*/

typedef struct s_lst t_lst;

typedef struct				s_lst
{
	t_lst		*prev;
	t_lst		*next;
}							t_lst;

typedef t_lst* node;
/*
** Sets a pointer on 0, so we can get rid of the offset of the given field
** and use its "absolute" address with OFFSETOF
**
** 1st parameter : structure type
** 2nd parameter : name of the list within the structure
*/
# define OFFSETOF(st, lst)				((char *)(&(((st *)0)->lst)))

/*
** Calculates the address of the structure thanks to the given address of
** the structure field. Because the offset is calculated by OFFSETOF, the
** difference gives directly the field width.
**
** 1st parameter : list pointer
** 2nd parameter : structure type
** 3rd parameter : name of the list within the structure
*/
# define CONTAINEROF(ptr, st, lst)	((st *)((char *)(ptr) - OFFSETOF(st, lst)))

/*
** Initializes the lst within a structure and sets prev and next pointers
** on itself. (NB : the structure needs to be allocated)
**
** 1st parameter : node to be init
*/
# define INIT_LST_HEAD(node)		(node).next = (node).prev = &(node)
# define INIT_LST_HEAD_P(node)		(node)->next = (node)->prev = node;

/*
** Prototypes
*/
void			ft_lst_add_next(node new, node dst);
void			ft_lst_add_prev(node new, node dst);
void			ft_lst_del(node ref);
void			ft_lst_disconnect(node src);
void			ft_lst_foreach(node lst, void (*f)(node));
void			ft_lst_moveto_next(node src, node dst);
void			ft_lst_moveto_prev(node src, node dst);
void			ft_lst_swap(node a, node b);
void			ft_lst_split(node src, node front, node back);
void			ft_lst_sorted_merge(node src,
									node a,
									node b,
									int (*f)(node, node));
void			ft_lst_merge(node src, node dst);
void			ft_lst_sorted_merge_array(int array[],
											int start, 
											int split,
											int stop);

int				ft_lst_is_head(node lst);
int				ft_lst_is_single(node lst);

node			ft_lst_new_node(void);

/*
** Sorting algorithm
*/
void			ft_lst_mergesort(node lst, int (*f)(node, node));
void			ft_lst_bubblesort(node lst, int (*f)(node, node));
void			ft_lst_insertsort(node lst, int (*f)(node, node));
void			ft_lst_selectsort(node lst, int (*f)(node, node));
void			ft_lst_quicksort(node lst, int (*f)(node, node));

#endif
