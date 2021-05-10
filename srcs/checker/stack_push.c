#include "checker.h"

void	stack_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from)
		exit(29);
	if (!to)
	{
		to = malloc(sizeof(t_stack *));
		temp = stack_last(*from);
		if (temp->prev)
			temp->prev->next = NULL;
		temp->prev = NULL;
		*to = temp;
		if (*from == temp)
			*from = NULL;
		return ;
	}
	temp = stack_last(*to);
	temp->next = stack_last(*from);
	if (temp->next->prev)
		temp->next->prev->next = NULL;
	temp->next->prev = temp;
}
