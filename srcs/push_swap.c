#include "push_swap.h"
#include <stdio.h>

static int	is_sort(t_node *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		if (i != stack->i)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2 || av[1] == 0)
		return (0);
	stack = create_stack(ac, av);
	if (!stack)
		return (0);
	add_index(stack, ac - 1);
	if (is_sort(stack->a_head))
	{
		free_node(stack->a_head);
		return (0);
	}
	solve(stack, ac - 1);
	free_node(stack->a_head);
	free_node(stack->pivot);
	free(stack);
	return (0);
}
