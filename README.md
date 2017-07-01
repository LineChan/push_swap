PUSH SWAP 

#   Subject   :pushpin:

Push_swap is a sorting game thats requires *two programs* :
- **push_swap** : You only have two stacks to sort the puzzle. At first, a stack (called Stack A) contains a certain amount of unduplicated integers and a second one (Stack B) is empty. The goal is to have all the number sorted in increasing order in Stack A. The output of the program is a list of instructions.
- **checker** : read the instructions and execute them. It checks if  Stack A is correctly sorted and Stack B empy. It sends "OK" to stdin if it is the case, otherwise it sends "KO"

Instructions are pre-defined by the subject and will the only reference to measure the performance of both programs during the peer-evaluation. Of course the less, the better.
There are 4 types of instructions :
- **push** (pa, pb) : moves the first element of a stack to the beginning of the other one
- **swap** (sa, sb, ss) : swap the two first elements of a stack
- **rotate** (ra, rb, rr) : first element comes last
- **reverse rotate** (rra, rrb, rrr) : last element comes first

The instruction is ignored if the instruction cannot be executed (for instance if the stack is empty).

Allowed functions : write, malloc, free, exit

### Libraries :books:
- **libft** : personnal library with functions from libc and printf from stdin
- **libst** : personnal library with a set of tools to manipulate Linux-like linked lists
- **ncurse** : for bonuses only

#  Method 

Different methods are used according to the number of elements to sort to reach the objectives asked by the correction.
- **sort_three** sorts 3 element with less than 3 instructions
- **sort_seven** sorts 7 elements with less than 12 instructions
- **insert_sort** sorts short lists (with less than 20 elements)
- **quick_sort** is used for every other lists. Sort 100 elements with less than 900 instructions, and around 6600 for 500 elements. This is an average number, see :arrow_down: for further details.

## Quicksort described step-by-step

The algorithm is a while loop with 2 algorithms, one called quick_a directly followed by another one called quick_b. The loop stops when Stack A is sorted and Stack B is either empty or reverse sorted. In the second case, all elements in Stack B are pushed back to Stack A.

### quick_a routine
```C

void		ft_ps_quick_a(void)
{
	int	pivot;
	int	pushed;
	node	left;

	pushed = 0;
	while (NB_ELEM_A > 1)
	{
		/* Top element on Stack A is selected as pivot */
		pivot = DATA(HEAD_A.next);
	
		/* It is also tagged as SORTED to indicate it will be pushed
		 at its correct  location on Stack B */
		SORTED(HEAD_A.next) = 1;

		left = TOP_A;
		/* We go through Stack A and compare elements with the pivot */
		/* Lower elements are sent to Stack B */
		if (ft_there_is_left_to_sort(&left, &pivot))
		{
			ft_push_lower(&left, &pushed, &pivot);
			if (ft_exec_head_is_sorted(&HEAD_A))
			{
				ft_ps_find_shortest_path(&HEAD_A, DATA(HEAD_A.next));
				break ;
			}
		}
		else
		{
			/* When top of Stack A is on the pivot again,*/
			/* it is pushed to Stack B */
			ft_stack_a_routine(&pushed, &pivot);
		}
	}
}
```
This process goes on until Stack A is sorted or if there is a single value remaining.

### quick_b routine

We apply the same process to Stack B. However, two things are now different :
	
1. Stack B now has a number of sections separated by tagged elements.These elements can not be selected as pivot again. Whenever there is a tagged element at the top of Stack B, it is poped to Stack A until there until an untagged element is at the top. This latter element is tagged and used as a pivot. The process is repeated until a tagged element is met again or if Stack B is empty.
	
2. If the section has less than 30 elements (numbers of elements in Stack B between the new pivot and the next tagged element), there are sorted thanks to an selectsort based algorithm.
```C
void	ft_quick_select(int *pushed, int *pivot)
{
	/* Push all the values between two pivots
	and selects the greastest value each time */
	while (*pushed)
	{
		ft_ps_push_max(&HEAD_B, *pushed);
		--*pushed;
	}
	
	if (ft_exec_head_is_sorted(&HEAD_A) &&
			(ft_ps_head_is_reverse_sorted(&HEAD_B) || !NB_ELEM_B))
		return ;
	
	/* Pushback everything to Stack B */
	while (DATA(TOP_A) < *pivot)
		ft_exec_pb();
}
```

### Worse case performance :boom:
This quicksort-like algorithm seems to share the advantages and disavantages than Hoare’s Quicksort. Best cases occurs when the first pivot breaks Stack A in halves (or close to) and worse performances occur when elements are almost in order or reverse order.

## Bonuses :star:

- [x] help option
- [x] "advanced" parsing :  0 "4 2" 1 6"    3  7" 8
- [x] option to clear up all redondant moves (ex : pb then pa)
- [x] interactive display of both stacks at each step
- [x] display of the instrucstions
- [x] write instructions in a .txt file and read from
---> -x : visual mode

#  Sources :bookmark_tabs: 

- Linux-like linked list : 
	- [*Data structure in Linux Kernel*](https://0xax.gitbooks.io/linux-insides/content/DataStructures/dlist.html)
	- [*Torvalds github*](https://github.com/torvalds/linux/blob/master/include/linux/list.h)
- Sorting methods
	- [*stack-based algorithms*](http://liacs.leidenuniv.nl/~rijnjnvan/ds2013/assets/opdrachten/opdracht1-stacksorting.pdf)



#  Result
Peer evaluation not done yet.
