PUSH SWAP 

-- Subject --
============

Push_swap is a sorting game thats requires two programs :
- push_swap : You only have two stacks to sort the puzzle. At first, a stack (called stack_a) contains a certain amount of unduplicated integers and a second one (stack_b) is empty. The goal is to have all the number sorted in increasing order in stack_a. The output of the program is a list of instructions.
- checker : read the instructions and execute them. It checks if  stack_a is correctly sorted and stack_b empy. It sends "OK" to stdin if it is the case, otherwise it sends "KO"

Instructions are pre-defined by the subject and will the only reference to measure the performance of both programs during the peer-evaluation. Of course the less, the better.
There are 4 types of instructions :
- push (pa, pb) : moves the first element of a stack to the beginning of the other one
- swap (sa, sb, ss) : swap the two first elements of a stack
- rotate (ra, rb, rr) : first element comes last
- reverse rotate (rra, rrb, rrr) : last element comes first

The instruction is ignored if the instruction cannot be executed (for instance if the stack is empty).

Allowed functions : write, malloc, free, exit

Libraries :
- libft : personnal library with functions from libc and printf from stdin
- libst : personnal library with a set of tools to manipulate linux-like linked lists
- ncurse : for bonuses only

-- Sources --
=============

- Linux-like linked list : 
	- [*Data structure in Linux Kernel*](https://0xax.gitbooks.io/linux-insides/content/DataStructures/dlist.html)
	- [*Torvalds github*](https://github.com/torvalds/linux/blob/master/include/linux/list.h)
- Sorting methods
	- [*3-stack based algorithms*](http://liacs.leidenuniv.nl/~rijnjnvan/ds2013/assets/opdrachten/opdracht1-stacksorting.pdf)

-- Method --
============

Different methods are used according to the number of elements to sort to reach the objectives asked during the peer-correction.
- sort_three sorts 3 element with less than 3 instructions
- sort_seven sorts 7 elements with less than 12 instructions
- insert_sort sorts short lists (with less than 20 elements)
- quick_sort is used for every other lists. Sort 100 elements with less than 900 instructions, and around 6600 for 500 elements. This is an average number, see below for further details.

Quicksort described step-by-step

The algorithm is a while loop with 2 algorithms, one called quick_a directly followed by another one called quick_b. The loop stops when stack_a is sorted and stack_b is either empty or reverse sorted. In the second case, all elements in stack_b are pushed to stack_a.

quick_a routine :
```C

void		ft_ps_quick_a(void)
{
	int	pivot;
	int	pushed;
	node	left;

	pushed = 0;
	while (NB_ELEM_A > 1)
	{
		pivot = DATA(HEAD_A.next);
		SORTED(HEAD_A.next) = 1;
		left = TOP_A;
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
			ft_stack_a_routine(&pushed, &pivot);
	}
}
```
Top element on stack_a is read out and selected as a pivot. The pivot is tagged as sorted to indicate that it will be pushed to its correct location in stack_b.
Then we go through stack_a and compare the elements with the pivot. Lower elements are sent to stack_b. When the top of stack_a is on the pivot again, it is pushed to stack_b. This process goes on until stack_a is sorted or if there is a single value remaining.

quick_b routine :
```C

void	ft_ps_quick_b(void)
{
	int	pivot;
	int	size;
	node	left;

	while (NB_ELEM_B)
	{
		if (ft_ps_head_is_reverse_sorted(&HEAD_B))
			return ;
		pivot = DATA(TOP_B);
		if (SORTED(TOP_B))
		{
			ft_exec_pa();
		}
		else
		{
			SORTED(TOP_B) = 1;
			left = HEAD_B.prev;
			if (ft_find_upper(&left, &pivot))
				ft_stack_b_routine(&left, &size, &pivot);
			else
			{
				ft_exec_pa();
			}
		}
	}
}
```
We apply the same process to stack_b. However, some things are now different :
- stack_b now has a number of sections separated by tagged elements.These elements can not be selected as pivot again. Whenever there is a tagged element at the top of stack_b, it is poped to stack_a until there until an untagged element is at the top. This latter element is tagged and used as a pivot.
- if the section has less than 30 elements (numbers of elements in stack_b between the new pivot and the next tagged element), there are sorted thanks to an selectsort based algorithm.
	```C
void	ft_quick_select(int *pushed, int *pivot)
{
	while (*pushed)
	{
		ft_ps_push_max(&HEAD_B, *pushed);
		--*pushed;
	}
	if (ft_exec_head_is_sorted(&HEAD_A) &&
			(ft_ps_head_is_reverse_sorted(&HEAD_B) || !NB_ELEM_B))
		return ;
	while (DATA(TOP_A) ^ *pivot)
		ft_exec_pb();
}
```
The process is repeated until a tagged element is met again or if stack_b is empty.

-- SPEC ---

---> example "advanced" parsing :  0 "4 2" 1 6"    3  7" 8

---> Linux like linked list (src : //website )





-- BONUS -- 

---> -clean : remove all redondant moves (ex : pb then pa)
---> -x : visual mode



-- RESULTS - FINAL GRADE ? --
=============================
Peer evaluation not done yet.
