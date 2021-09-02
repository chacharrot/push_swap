#include "push_swap.h"

int		check_arg(char *av)
{
	int	i;

	i = 0;
	if ('-' == av[i] || '+' == av[i])
		i++;
	while (av[i])
	{
		if ('0' > av[i] || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		check_int_range(long long n)
{
	if (-2147483648 <= n && n <= 2147483647)
		return (1);
	return (0);
}

int		check_double(t_node *node)
{
	t_node *diff;

	while (node != NULL)
	{
		diff = node->next;
		while (diff != NULL)
		{
			if (node->nbr == diff->nbr)
				return (0);
			diff = diff->next;
		}
		node = node->next;
	}
	return (1);
}
