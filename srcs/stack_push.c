#include "push_swap.h"

void	stack_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!(*from))
		return ;
	if (!*to)
	{
		*to = stack_last(*from);
		(*to)->prev->next = NULL;
		(*to)->prev = NULL;
		(*to)->next = NULL;
	}
	else
	{
		temp = stack_last(*from);
		if (temp == *from)
			*from = NULL;
		else
			temp->prev->next = NULL;
		temp->prev = stack_last(*to);
		temp->prev->next = temp;
	}
}
