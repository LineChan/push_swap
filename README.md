PUSH SWAP 

-- SUBJECT --
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

If the instruction cannot be executed (for instance if the stack is empty) it is ignored.

Allowed functions : write, malloc, free, exit

Libraries :
- libft : personnal library with functions from libc and printf from stdin
- libst : personnal library with a set of tools to manipulate linux-like linked lists.
- ncurse : for bonuses only


-- METHOD --

-- sort 3 elem with less than 3 moves : sort_three

-- sort 7 elem with less than 12 moves : sort_seven (using sort_three)

-- sort 20 elem with less than x moves : insert_sort (using sort_three)

-- sort 100 elem with less than 900 moves : quick_sort

-- sort 500 elems with less than x moves : quick_sort 




-- SPEC ---

---> example "advanced" parsing :  0 "4 2" 1 6"    3  7" 8

---> Linux like linked list (src : //website )





-- BONUS -- 

---> -clean : remove all redondant moves (ex : pb then pa)
---> -x : visual mode



-- RESULTS - FINAL GRADE ? --
