#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define STACK_A 0
# define STACK_B 1

# define PUSH 0
# define SWAP 1
# define ROTATE 2
# define REV_ROTATE 3

typedef struct		s_stack
{
	int				item;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int		check_args(int argc, char **argv);
t_stack	*get_stack_from_args(int argc, char **argv);
void	print_stacks(t_stack *a, t_stack *b);
int		run_command(t_stack **a, t_stack **b, char *line);
int		is_sorted(t_stack *a);

t_stack	*stack_swap(t_stack *stack);
void	stack_push(t_stack **from, t_stack **to);
t_stack	*stack_rotate(t_stack *stack);
t_stack	*stack_rev_rotate(t_stack *stack);
t_stack *stack_first(t_stack *stack);
t_stack *stack_last(t_stack *stack);
size_t	stack_size(t_stack *stack);

t_stack	*stack_run(int command, int a_or_b, t_stack *stack);
void	stack_run_push(int from_a_or_b, t_stack **from, t_stack **to);

size_t	get_big_num_pos(t_stack *stack);
size_t	get_small_num_pos(t_stack *stack);
t_stack	*smallest_to_top(t_stack *stack, int a_or_b);

t_stack	*sort(t_stack *stack, int a_or_b);

t_stack	*sort_2(t_stack *stack, int a_or_b);
t_stack	*sort_3(t_stack *stack, int a_or_b);

t_stack	*generic_sort_5(t_stack *stack, int a_or_b);
t_stack	*generic_sort_100(t_stack *stack, int a_or_b);

#endif
