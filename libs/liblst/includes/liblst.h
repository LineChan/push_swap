/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 17:07:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/06 17:09:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLST_H
# define LIBLST_H
# include <stdint.h>

typedef struct	s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
}				t_lst;

/*
** Sets a pointer on 0, so we can get rid of the offset of the given field
** and use its "absolute" address with OFFSETOF
**
** 1st parameter : structure type
** 2nd parameter : name of the list within the structure
*/
# define OFFSETOF(st, lst)			((char *)(&(((st *)0)->lst)))

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
# define INIT_LST_HEAD(it)			(it).next = (it).prev = &(it)
# define INIT_LST_HEAD_P(it)		(it)->next = (it)->prev = it;

/*
** Prototypes
*/
void			ft_lst_add_next(t_lst *new, t_lst *dst);
void			ft_lst_add_prev(t_lst *new, t_lst *dst);
void			ft_lst_del(t_lst *ref);
void			ft_lst_disconnect(t_lst *src);
void			ft_lst_foreach(t_lst *lst, void (*f)(t_lst *));
void			ft_lst_moveto_next(t_lst *src, t_lst *dst);
void			ft_lst_moveto_prev(t_lst *src, t_lst *dst);
void			ft_lst_swap(t_lst *a, t_lst *b);
void			ft_lst_split(t_lst *src, t_lst *front, t_lst *back);
void			ft_lst_sorted_merge(t_lst *src,
									t_lst *a,
									t_lst *b,
									int (*f)(t_lst *, t_lst *));
void			ft_lst_merge(t_lst *src, t_lst *dst);
void			ft_lst_sorted_merge_array(int array[],
									int start,
									int split,
									int stop);

int				ft_lst_is_head(t_lst *lst);
int				ft_lst_is_single(t_lst *lst);

t_lst			*ft_lst_new_node(void);

/*
** Sorting algorithm
*/
void			ft_lst_mergesort(t_lst *lst, int (*f)(t_lst *, t_lst *));
void			ft_lst_bubblesort(t_lst *lst, int (*f)(t_lst *, t_lst *));
void			ft_lst_insertsort(t_lst *lst, int (*f)(t_lst *, t_lst *));
void			ft_lst_selectsort(t_lst *lst, int (*f)(t_lst *, t_lst *));
void			ft_lst_quicksort(t_lst *lst, int (*f)(t_lst *, t_lst *));

#endif
