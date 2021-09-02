#include "push_swap.h"

void	swapper(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "sa"))
	{
		swap(&stack->a_head);
		write(1, "sa\n", 3);
		return ;
	}
	if (!ft_strcmp(line, "sb"))
	{
		swap(&stack->b_head);
		write(1, "sb\n", 3);
		return ;
	}
	swap(&stack->a_head);
	swap(&stack->b_head);
	write(1, "ss\n", 3);
}

void	rotater(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "ra"))
	{
		rotate(&stack->a_head, &stack->a_tail);
		write(1, "ra\n", 3);
		return ;
	}
	if (!ft_strcmp(line, "rb"))
	{
		rotate(&stack->b_head, &stack->b_tail);
		write(1, "rb\n", 3);
		return ;
	}
	rotate(&stack->a_head, &stack->a_tail);
	rotate(&stack->b_head, &stack->b_tail);
	write(1, "rr\n", 3);
}

void	rev_rotater(char *line, t_stack *stack)
{
	if (!ft_strcmp(line, "rra"))
	{
		rev_rotate(&stack->a_head, &stack->a_tail);
		write(1, "rra\n", 4);
		return ;
	}
	if (!ft_strcmp(line, "rrb"))
	{
		rev_rotate(&stack->b_head, &stack->b_tail);
		write(1, "rrb\n", 4);
		return ;
	}
	rev_rotate(&stack->a_head, &stack->a_tail);
	rev_rotate(&stack->b_head, &stack->b_tail);
	write(1, "rrr\n", 4);
}
