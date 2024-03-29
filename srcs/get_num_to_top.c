#include "push_swap.h"

static t_stack	*poop(t_stack *stack, int a_or_b, size_t distance,
					int top_or_bot);

t_stack	*get_num_to_top(int num, t_stack *stack, int a_or_b)
{
	int		top_or_bot;
	t_stack	*top;
	t_stack	*bot;
	size_t	distance;

	distance = distance_to_top(num, stack);
	top = stack_last(stack);
	bot = stack;
	while (1)
	{
		if (top->item == num)
		{
			top_or_bot = TOP;
			break ;
		}
		else if (bot->item == num)
		{
			top_or_bot = BOT;
			break ;
		}
		top = top->prev;
		bot = bot->next;
	}
	stack = poop(stack, a_or_b, distance, top_or_bot);
	return (stack);
}

static t_stack	*poop(t_stack *stack, int a_or_b, size_t distance,
						int top_or_bot)
{
	if (top_or_bot == TOP)
		while (distance--)
			stack = stack_run(ROTATE, a_or_b, stack);
	else if (top_or_bot == BOT)
		while (distance--)
			stack = stack_run(REV_ROTATE, a_or_b, stack);
	return (stack);
}
