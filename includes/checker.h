#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_stack
{
	int				item;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

t_stack	*stack_init(int *items, size_t size);
t_stack	*stack_swap(t_stack *stack);
t_stack	*stack_push(t_stack *from, t_stack *to);
t_stack	*stack_rotate(t_stack *stack);
t_stack	*stack_rev_rotate(t_stack *stack);
t_stack *stack_first(t_stack *stack);
t_stack *stack_last(t_stack *stack);
size_t	stack_size(t_stack *stack);
#endif
