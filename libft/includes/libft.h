/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:40:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/05/18 09:27:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** For write
*/
# include <unistd.h>

/*
** For limits
*/
# include <limits.h>

/*
** For sizeof and malloc
*/
# include <stdlib.h>

/*
** ft_printf
*/
# include "ft_printf.h"

/*
** get_next_line
*/
# include "get_next_line.h"

/*
** error
*/
#include "error.h"

/*
** assert define
*/
#define ASSERT(x)	ft_assert(#x, __FUNCTION__, x);

/*
** Number of bits and mask sign
*/
# define NB_BIT 8
# define MASK_SIGN ((sizeof(int) * NB_BIT) - 1)

/*
** Functions
*/
# define SWAP(x,y) (x ^= y ^= x ^= y)
# define ABS(x) ((x + (x >> MASK_SIGN)) ^ (x >> MASK_SIGN))
# define SIZEOF(x) (sizeof(x)/sizeof(x[0]))

/*
** Returns 1 if a and b have opposite signs
*/
# define OP_SIGN(x,y) ((x ^ y) < 0)

/*
** Returns 1 if x is negative ( looking at the far left bit )
*/
# define IS_NEG(x) ((unsigned int)x >> MASK_SIGN)

/*
** Returns the minimum or the max of two int without branching
** (INT_MIN <= x - y <= INT_MAX)
*/
# define MIN(x,y) (y + ((x - y) & ((x - y) >> MASK_SIGN)))
# define MAX(x,y) (x - ((x - y) & ((x - y) >> MASK_SIGN)))

/*
** Returns 1 if the number is a power of 2
*/
# define POW_OF_TWO(x) (x && (!(x & (x - 1))))

/*
** Prototypes
*/
void			*ft_memalloc(size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t len);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *str);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(const char *str);
void			ft_putstr_fd(char const *str, int fd);
void			ft_strclr(char *str);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_swap(int *a, int *b);
void			ft_assert(char const *cond_str, char const *from, int cond);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_ispunct(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_isxdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_sqrt(int nb);
int				get_next_line(const int fd, char **line);
int				ft_uintlen(unsigned long int nb, unsigned long int base);
int				ft_intlen(long long int nb);
int				ft_wclen(wchar_t wc);
int				ft_wstrlen(wchar_t *ws);
int				ft_isblank(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_absolute(int c);
int				ft_isblank_cr(int c);

char			*ft_itoa(int n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_stpcpy(char *dst, const char *src);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_count_word(const char *str, char c);

#endif
