#include "push_swap.h"

static void	small_sort_3(t_stack *stack, int min, int max)
{
	if (stack->a_head->i == max - 1)
		rotater("ra", stack);
	if (stack->a_head->i == min)
	{
		if (stack->a_head->next->i == stack->a_head->i + 1)
			return ;
		else
		{
			swapper("sa", stack);
			rotater("ra", stack);
		}
	}
	else
	{
		if (stack->a_head->next->i > stack->a_head->i)
			rev_rotater("rra", stack);
		else
			swapper("sa", stack);
	}
}

static void	small_sort_5(t_stack *stack, int max)
{
	int		min;

	min = 0;
	while (min < max / 2)
	{
		if (stack->a_head->i < max / 2)
		{
			push("pb", stack);
			min += 1;
		}
		else
			rotater("ra", stack);
	}
	small_sort_3(stack, min, max);
	if (stack->b_head->i == 0)
		swapper("sb", stack);
	push("pa", stack);
	push("pa", stack);
}

static void	big_sort(t_stack *stack, int cnt)
{
	t_node	*now_pivot;

	now_pivot = stack->pivot;
	big_sort_split(stack, 0, now_pivot->i);
	while (now_pivot->next)
	{
		big_sort_split(stack, now_pivot->i, now_pivot->next->i);
		now_pivot = now_pivot->next;
	}
	big_sort_split(stack, now_pivot->i, cnt);
	big_sort_swap_first(stack, now_pivot->i, cnt);
	while (now_pivot->prev)
	{
		big_sort_swap_end(stack, now_pivot->prev->i, now_pivot->i);
		now_pivot = now_pivot->prev;
	}
	big_sort_swap_end(stack, 0, now_pivot->i);
}

void		solve(t_stack *stack, int max)
{
	if (max > 5)
		big_sort(stack, max);
	else
	{
		if (max <= 3)
			small_sort_3(stack, 0, max);
		else
			small_sort_5(stack, max);
	}
}
