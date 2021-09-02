#include "push_swap.h"

static void	big_sort_swap_end_check1_max(t_stack *stack, int *max)
{
	if (stack->a_head->i == (*max) - 1)
	{
		push("pa", stack);
		swapper("sa", stack);
		(*max) -= 2;
	}
	else
	{
		push("pa", stack);
		(*max) -= 1;
	}
}

static int	big_sort_swap_end_check1(t_stack *stack,
		int *min, int *max, int *min_check)
{
	if (stack->b_head->i == *min)
	{
		if (stack->a_tail->i == stack->b_head->i + 1)
		{
			rev_rotater("rra", stack);
			push("pa", stack);
			rotater("ra", stack);
			rotater("ra", stack);
			(*min) += 2;
		}
		else
		{
			push("pa", stack);
			rotater("ra", stack);
			(*min) += 1;
		}
		(*min_check)++;
	}
	else if (stack->b_head->i == *max)
		big_sort_swap_end_check1_max(stack, max);
	return (1);
}

static int	big_sort_swap_end_check2(t_stack *stack,
		int *min, int *max, int *min_check)
{
	if (stack->b_head->i == (*min) + 1)
	{
		push("pa", stack);
		rotater("ra", stack);
		(*min_check)++;
	}
	else if (stack->b_head->i == (*max) - 1)
		push("pa", stack);
	return (1);
}

static void	big_sort_swap_end_all_check(t_stack *stack,
		int min, int max, int *min_check)
{
	int		cnt;
	int		while_end;
	int		i;

	i = 0;
	cnt = 0;
	while_end = max - min + 1;
	while (i < while_end)
	{
		if (stack->b_head->i < min)
		{
			while (0 < cnt--)
			{
				rev_rotater("rrb", stack);
				if (stack->b_head->i == min || stack->b_head->i == max)
					i += big_sort_swap_end_check1(stack, &min, &max, min_check);
			}
		}
		else if (stack->b_head->i == min || stack->b_head->i == max)
			i += big_sort_swap_end_check1(stack, &min, &max, min_check);
		else if (stack->b_head->i == min + 1 || stack->b_head->i == max - 1)
			i += big_sort_swap_end_check2(stack, &min, &max, min_check);
		else if (0 <= cnt++)
			rotater("rb", stack);
	}
}

void	big_sort_swap_end(t_stack *stack, int min, int max)
{
	int		min_check;

	min_check = 0;
	big_sort_swap_end_all_check(stack, min, max - 1, &min_check);
	if (stack->a_head->i < stack->a_tail->i)
	{
		rev_rotater("rra", stack);
		swapper("sa", stack);
		min_check--;
	}
	while (min_check-- > 0)
		rev_rotater("rra", stack);
}
