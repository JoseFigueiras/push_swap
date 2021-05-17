#include "push_swap.h"

t_stack	*stack_run(int command, int a_or_b, t_stack *stack)
{
	if (command == SWAP)
	{
		stack = stack_swap(stack);
		if (a_or_b == STACK_A)
			write(1, "sa\n", 3);
		if (a_or_b == STACK_B)
			write(1, "sb\n", 3);
	}
	else if (command == ROTATE)
	{
		stack = stack_rotate(stack);
		if (a_or_b == STACK_A)
			write(1, "ra\n", 3);
		if (a_or_b == STACK_B)
			write(1, "rb\n", 3);
	}
	else if (command == REV_ROTATE)
	{
		stack = stack_rev_rotate(stack);
		if (a_or_b == STACK_A)
			write(1, "rra\n", 4);
		if (a_or_b == STACK_B)
			write(1, "rrb\n", 4);
	}
	return (stack_first(stack));
}
