#include "push_swap.h"

static void	push_a(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b_head == NULL)
		return ;
	tmp = stack->b_head;
	stack->b_head = stack->b_head->next;
	if (stack->b_head)
		(stack->b_head)->prev = NULL;
	if (stack->a_head)
		(stack->a_head)->prev = tmp;
	else
		stack->a_tail = tmp;
	tmp->next = stack->a_head;
	stack->a_head = tmp;
	stack->a_head->prev = NULL;
	write(1, "pa\n", 3);
}

static void	push_b(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a_head == NULL)
		return ;
	tmp = stack->a_head;
	stack->a_head = stack->a_head->next;
	if (stack->a_head)
		(stack->a_head)->prev = NULL;
	if (stack->b_head)
		(stack->b_head)->prev = tmp;
	else
		stack->b_tail = tmp;
	tmp->next = stack->b_head;
	stack->b_head = tmp;
	stack->b_head->prev = NULL;
	write(1, "pb\n", 3);
}

void		push(char *line, t_stack *stack)
{
	if (*(line + 1) == 'a')
		push_a(stack);
	if (*(line + 1) == 'b')
		push_b(stack);
}
