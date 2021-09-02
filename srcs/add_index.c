#include "push_swap.h"

static t_node	*create_pivot(t_stack *stack, t_node *pivot, int index)
{
	t_node		*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		exit(1);
	if (pivot == 0)
		stack->pivot = tmp;
	if (tmp)
	{
		tmp->nbr = 0;
		tmp->prev = pivot;
		tmp->next = NULL;
		tmp->i = index;
	}
	if (pivot != NULL)
		pivot->next = tmp;
	return (tmp);
}

static int	check_num(int max, int index, int i)
{
	int			num;

	num = 0;
	while (i--)
		num += max / index;
	return (num);
}

void	add_index(t_stack *stack, int max)
{
	t_node		*node;
	t_node		*diff;
	t_node		*pivot;
	int			index;
	int			i;

	pivot = 0;
	index = (max / 100) + 5;
	i = 0;
	while (++i < index)
		pivot = create_pivot(stack, pivot, check_num(max, index, i));
	node = stack->a_head;
	while (node != NULL)
	{
		diff = stack->a_head;
		while (diff != NULL)
		{
			if (node->nbr > diff->nbr)
				node->i++;
			diff = diff->next;
		}
		node = node->next;
	}
}
