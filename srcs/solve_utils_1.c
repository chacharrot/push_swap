#include "push_swap.h"

void	big_sort_split(t_stack *stack, int min, int max)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->a_head;
	while (tmp && i < (max - min))
	{
		tmp = stack->a_head;
		if (tmp->i < max)
		{
			push("pb", stack);
			i++;
		}
		else
			rotater("ra", stack);
	}
}

static void	big_sort_swap_first_rev(t_stack *stack,
		int *pivot_min, int *pivot_max, int *i)
{
	rev_rotater("rrb", stack);
	if (stack->b_head->i == *pivot_min)
	{
		push("pa", stack);
		(*i)++;
		(*pivot_min) -= 1;
	}
	else if (stack->b_head->i == *pivot_max)
	{
		push("pa", stack);
		rotater("ra", stack);
		(*i)++;
		(*pivot_max) += 1;
	}
}

static void	big_sort_swap_first_check(t_stack *stack,
		int *pivot_min, int *pivot_max, int *i)
{
	if (stack->b_head->i == *pivot_min)
	{
		push("pa", stack);
		(*i)++;
		(*pivot_min) -= 1;
	}
	else if (stack->b_head->i == *pivot_max)
	{
		push("pa", stack);
		rotater("ra", stack);
		(*i)++;
		(*pivot_max) += 1;
	}
}

void	big_sort_swap_first(t_stack *stack, int min, int max)
{
	int		pivot_min;
	int		pivot_max;
	int		i;
	int		cnt;

	pivot_min = (min + max) / 2;
	pivot_max = ((min + max) / 2) + 1;
	i = 0;
	cnt = 0;
	while (i < (max - min))
	{
		if (stack->b_head->i < min)
		{
			while (0 < cnt--)
				big_sort_swap_first_rev(stack, &pivot_min, &pivot_max, &i);
		}
		else if (stack->b_head->i == pivot_min || stack->b_head->i == pivot_max)
			big_sort_swap_first_check(stack, &pivot_min, &pivot_max, &i);
		else if (0 <= cnt++)
			rotater("rb", stack);
	}
}
