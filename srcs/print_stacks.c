#include "push_swap.h"

static size_t	stack_count_back(t_stack *stack);

void	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*acurrent;
	t_stack	*bcurrent;
	size_t	count_back_a;
	size_t	count_back_b;

	acurrent = stack_last(a);
	bcurrent = stack_last(b);
	while (acurrent || bcurrent)
	{
		count_back_a = stack_count_back(acurrent);
		count_back_b = stack_count_back(bcurrent);
		if (count_back_a >= count_back_b && count_back_a > 0)
		{
			printf("%4d", acurrent->item);			
			acurrent = acurrent->prev;
		}
		else
			printf("    ");
		printf(" ");
		if (count_back_b >= count_back_a && count_back_b > 0)
		{
			printf("%4d", bcurrent->item);
			bcurrent = bcurrent->prev;
		}
		else
			printf("    ");
		printf("\n");
	}
	printf("---- ----\n");
	printf("   a    b\n");
}

static size_t	stack_count_back(t_stack *stack)
{
	t_stack	*current;
	size_t	i;

	current = stack;
	i = 0;
	while (current)
	{
		current = current->prev;
		i++;
	}
	return (i);
}
