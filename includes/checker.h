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

int		check_args(int argc, char **argv);
t_stack	*get_stack_from_args(int argc, char **argv);
void	print_stacks(t_stack *a, t_stack *b);	//TODO
int		run_command(t_stack **a, t_stack **b, char *line);
int		is_sorted(t_stack *a, t_stack *b);

t_stack	*stack_init(int *items, size_t size);
t_stack	*stack_swap(t_stack *stack);
void	stack_push(t_stack **from, t_stack **to)
t_stack	*stack_rotate(t_stack *stack);
t_stack	*stack_rev_rotate(t_stack *stack);
t_stack *stack_first(t_stack *stack);
t_stack *stack_last(t_stack *stack);
size_t	stack_size(t_stack *stack);

#endif
