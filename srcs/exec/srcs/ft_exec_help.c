#include "push_swap.h"

/*
** Display help page
*/
void		ft_exec_help(void)
{
	ft_printf("\n\nWelcome to the help page !\n\nHOW TO USE push_swap\n\n");
	ft_printf("\t./push_swap [--{cyan:help}] [--{green:clean}] ");
	ft_printf("[-{yellow:x}] [{red:args} ...]\n\n");
	ft_printf(" {cyan:%6s} : displays the help page\n ", "help");
	ft_printf("{green:%6s} : checks for known patterns and removes them\n", "clean");
	ft_printf(" {yellow:%6s} : writes instruction in a .txt file\n ", "x");
	ft_printf("{red:%6s} : integers to be sorted. Sends an {RED:ERROR} if :", "args");
	ft_printf("\n\t\t- the parameter is not a number\n\t\t- the number is not");
	ft_printf(" an integer\n\t\t- there are duplicated elements\n");
	ft_printf("\t\t- [2 6 3 5 7 1 4], \n\t\t  [\"2 6 3 5 7 1 4\"]\n\t\t  [2 \"6     3 \"5 7 \"1  \" 4] are the same expression\n\nHOW TO");
	ft_printf(" USE checker\n\n\t./checker [-{yellow:x}] [{red:args} ...]");
	ft_printf("\n\n  {yellow:%6s} : reads instructions from a file\n  ", "x");
	ft_printf("{red:%6s} : integers to be sorted. Sends an {RED:ERROR} if :", "args");
	ft_printf("\n\t\t- the parameter is not a number\n\t\t- the number is not");
	ft_printf(" an integer\n\t\t- there are duplicated elements\n");
	ft_printf("\t\t- [2 6 3 5 7 1 4], \n\t\t  [\"2 6 3 5 7 1 4\"]\n\t\t  [2 \"6     3 \"5 7 \"1  \" 4] are the same expression\n\n");
	ft_printf("HOW TO USE push_swap with checker\n\n\t> ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker $ARG\n\t> ./push_swap --clean 2 6 3 5 7 1 4 | ./checker 2 6 3 5 7 1 4\n\n");
	ft_printf("HOW TO VIZUALIZE the algorithms\n\n\t> ./push_swap --clean -x 2 6 3 5 && ./checker -x  2 6 3 5\n\n");
}
