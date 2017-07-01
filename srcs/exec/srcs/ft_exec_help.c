#include "push_swap.h"

/*
** Display help page
*/
void		ft_exec_help(void)
{
	ft_printf("\n\nWelcome to the help page !\n\nHOW TO USE push_swap\n\n");
	ft_printf("\t./push_swap [{cyan:--help}] [{green:--clean}] ");
	ft_printf("[{yellow:-x}] [{red:args} ...]\n\n");
	ft_printf("  {cyan:help} : displays the help page\n  ");
	ft_printf("{green:clean} : checks for known patterns and removes them\n");
	ft_printf("  {yellow:x} : writes instruction in a .txt file\n  ");
	ft_printf("{red:args} : integers to be sorted. Sends an {RED:ERROR} if :");
	ft_printf("\n\t\t- the parameter is not a number\n\t\t- the number is not");
	ft_printf(" an integer\n\t\t- there are duplicated elements\n\n");
}
