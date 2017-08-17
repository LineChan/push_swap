#include "../../includes/ft_printf.h"

/*
** Initializing all t_struct arg parameters
*/

void		ft_printf_init_struct(t_struct *arg)
{
	arg->type = 0;
	arg->rdm = 0;
	arg->padd = 0;
	arg->dot = 0;
	arg->neg = 0;
	arg->flag = 0;
	NB_COLOR = 0;
}
