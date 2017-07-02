#include "push_swap.h"

/*
** Display help page
*/
void		ft_exec_help(void)
{
	PRINTF("\n\nWelcome to the help page !\n\nHOW TO USE push_swap\n\n");
	PRINTF("\t./push_swap [--{cyan:help}] [--{green:clean}] [-{yellow:x}] ");
	PRINTF("");
	PRINTF("[{red:args} ...]\n\n {cyan:%6s} : displays the help page", "help");
	PRINTF(" \n {green:%6s} : checks for known patterns and removes", "clean");
	PRINTF(" them\n {yellow:%6s} : writes instruction in a .txt file", "x");
	PRINTF("\n {red:%6s} : integers to be sorted. Sends an ", "args");
	PRINTF("{RED:ERROR} if :\n\t\t- the parameter is not a number\n\t\t- the");
	PRINTF(" number is not an integer\n\t\t- there are ");
	PRINTF("duplicated elements\n\t\t- [2 6 3 5 7 1 4] \n\t\t  [\"2 6 3 5 7");
	PRINTF("1 4\"]\n\t\t  [2 \"6     3 \"5 7 \"1  \" 4]\n\t\t  are the same");
	PRINTF(" expression\n\nHOW TO USE checker\n\n\t./checker [-{yellow:x}] ");
	PRINTF("[{red:args} ...]\n\n  {yellow:%6s} : reads instructions from", "x");
	PRINTF(" a file\n  {red:%6s} : integers to be sorted. Sends an", "args");
	PRINTF(" {RED:ERROR} if :\n\t\t- the parameter is not a number\n\t\t");
	PRINTF("- the number is not an integer\n\t\t- there are duplicated");
	PRINTF(" elements\n\t\t- [2 6 3 5 7 1 4], \n\t\t  [\"2 6 3 5 7 1 4\"]");
	PRINTF("\n\t\t  [2 \"6     3 \"5 7 \"1  \" 4]\n\t\t  are the same ");
	PRINTF("expression\n\nHOW TO USE push_swap with checker\n\n\t> ");
	PRINTF("ARG=\"4 67 3 87 23\";./push_swap $ARG | ./checker $ARG\n\t");
	PRINTF("> ./push_swap --clean 2 6 3 5 7 1 4 | ./checker 2 6 3 5 7 1 4");
	PRINTF("\n\nHOW TO VIZUALIZE the algorithms\n\n\t> ./push_swap --clean ");
	PRINTF("-x 2 6 3 5 && ./checker -x  2 6 3 5\n\n");
}
