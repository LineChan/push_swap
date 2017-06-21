/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 23:06:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/06 09:20:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** Personal libc
*/
# include "libft.h"

/*
** va_list
*/
# include <stdarg.h>

/*
** To setlocale for UNICODES
*/
# include <locale.h>

/*
** To use the wchar_t type
*/
# include <wchar.h>

/*
** limits
*/
# include <limits.h>

/*
** Buffer size - min : 55 (ULL in base 2)
*/
# define BUFF_MAX 0x64
# define NB_COLORS_MAX 0x20

/*
** Strings
*/
# define SIZE			(arg->p - arg->buff)
# define NB_COLOR		(arg->color_ptr)
# define TYPE			("sSpdDioOuUxXcCbB%")
# define MOD_LIST		("hljz")
# define ULL			unsigned long long
# define LL				long long
# define UP				("0123456789ABCDEFGH")
# define LOW			("0123456789abcdefgh")

/*
** Define flags
*/
# define FLAG_MINUS		0x1
# define FLAG_PLUS		0x10
# define FLAG_ZERO		0x100
# define FLAG_SPACE		0x1000
# define FLAG_SHARP		0x10000
# define FLAG_DOT		0x100000
# define FLAG_WILD		0x1000000
# define FLAG_WILD_DOT	0x10000000
# define FLAG_WILD_DOT2	0x100000000

/*
** Define mods
*/
# define MOD_HH			0x1000000000
# define MOD_H			0x10000000000
# define MOD_LL			0x100000000000
# define MOD_L			0x1000000000000
# define MOD_J			0x10000000000000
# define MOD_Z			0x100000000000000

/*
** Comparisons
*/
# define MINUS		(arg->flag & FLAG_MINUS)
# define PLUS		(arg->flag & FLAG_PLUS)
# define ZERO		(arg->flag & FLAG_ZERO)
# define SPACE		(arg->flag & FLAG_SPACE)
# define SHARP		(arg->flag & FLAG_SHARP)
# define DOT		(arg->flag & FLAG_DOT)
# define WILD		(arg->flag & FLAG_WILD)
# define WILD_D		(arg->flag & FLAG_WILD_DOT)
# define WILD_D2	(arg->flag & FLAG_WILD_DOT2)
# define M_HH		(arg->flag & MOD_HH)
# define M_H		(arg->flag & MOD_H)
# define M_LL		(arg->flag & MOD_LL)
# define M_L		(arg->flag & MOD_L)
# define M_J		(arg->flag & MOD_J)
# define M_Z		(arg->flag & MOD_Z)

/*
** Structures
*/
typedef struct			s_struct
{
	char				type;
	char				rdm;
	char				*p;
	char				buff[BUFF_MAX + 1];
	int					padd;
	int					dot;
	int					neg;
	int 				fd;
	int					color_ptr;
	unsigned long		flag;
	va_list				ap;
}						t_struct;

typedef struct			s_printf
{
	char const			c;
	void				(*func)(t_struct *);
}						t_printf;

typedef enum			e_printf_redir
{
	ft_stdin = 0,
	ft_stdout = 1,
	ft_stderr = 2,
}						e_printf_redit;

/*
** Prototypes
*/
int						ft_printf(const char *format, ...);
int						ft_fprintf(int const fd, const char *s, ...);
int						*ret(void);
void					ft_printf_write_buff(t_struct *arg);
int						ft_printf_unicode_string(t_struct *arg, wchar_t wc);
void					ft_printf_parsing(char *s, t_struct *arg);
void					ft_printf_colors(char **s, t_struct *arg);
void					ft_printf_end_colors(char **s, t_struct *arg);
void					ft_printf_init_struct(t_struct *arg);
void					ft_printf_analyse(char c, t_struct *arg);
void					ft_printf_find_type(char c, t_struct *arg);
void					ft_printf_string(t_struct *arg);
void					ft_printf_lc(t_struct *arg, wchar_t wc);
void					ft_printf_ls(t_struct *arg);
void					ft_printf_int(t_struct *arg);
void					ft_printf_pointer(t_struct *arg);
void					ft_printf_putnbr_p(unsigned long long p, t_struct *arg);
void					ft_printf_hexa(t_struct *arg);
void					ft_printf_hexa_zero(t_struct *arg);
void					ft_printf_octal(t_struct *arg);
void					ft_printf_unsigned(t_struct *arg);
void					ft_printf_modulo(t_struct *arg);
void					ft_printf_binary(t_struct *arg);
void					ft_printf_wild(t_struct *arg);
long long int			ft_printf_convert_id(t_struct *arg);
unsigned long long		ft_printf_convert_unsigned(t_struct *arg);

#endif
