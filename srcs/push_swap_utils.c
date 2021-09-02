#include "push_swap.h"

long long				ft_atol(const char *nptr)
{
	unsigned long long	num;
	int					sign;
	int					i;

	num = 0;
	sign = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] == '0')
		i++;
	while (nptr[i])
	{
		num *= 10;
		num = num + nptr[i] - '0';
		if (i >= 18)
			return(num);
		i++;
	}
	return (num * sign);
}

int						ft_strcmp(const char *s1, const char *s2)
{
	int					i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void					free_node(t_node *stack)
{
	t_node				*tmp;
	t_node				*next;

	if (stack != NULL)
	{
		tmp = stack;
		while (tmp->next != NULL)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		free(tmp);
	}
}
