#include "push_swap.h"

void	stack_run_push(int from_a_or_b, t_stack **from, t_stack **to)
{
	stack_push(from, to);
	if (from_a_or_b == STACK_A)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}
