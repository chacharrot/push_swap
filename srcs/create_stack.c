#include "push_swap.h"

static t_node	*create_node(char *av, t_node *now_node)
{
	t_node		*tmp;
	long long	num;

	if (!(check_arg(av)))
		return (0);
	num = ft_atol(av);
	if (!(check_int_range(num)))
		return (0);
	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (0);
	if (tmp)
	{
		tmp->nbr = num;
		tmp->prev = now_node;
		tmp->next = NULL;
		tmp->i = 0;
	}
	if (now_node != NULL)
		now_node->next = tmp;
	return (tmp);
}

static void	print_error(t_stack *stack)
{
	free_node(stack->a_head);
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack		*stack;
	t_node		*now_node;
	int			i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	i = 1;
	now_node = NULL;
	while (i < ac)
	{
		now_node = create_node(av[i], now_node);
		if (!now_node)
			print_error(stack);
		if (i == 1)
			stack->a_head = now_node;
		if (++i == ac)
			stack->a_tail = now_node;
	}
	if (!(check_double(stack->a_head)))
		print_error(stack);
	stack->b_head = 0;
	stack->b_tail = 0;
	stack->pivot = 0;
	return (stack);
}
