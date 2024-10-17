/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:55:11 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 17:17:12 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isdigit_ps(int c)
{
	if ((c >= 48 && c < 58) || c == 32)
		return (true);
	else
		return (false);
}

long	ft_atol(const char *nptr)
{
	long	result;
	long	i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

int	node_len(t_node *stack)
{
	t_node	*ptr;
	int		i;

	i = 0;
	ptr = stack;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	find_max_value(t_node *stack)
{
	t_node	*sa_ptr;
	int		max_value;
	int		index;

	sa_ptr = stack;
	max_value = 0;
	index = 0;
	while (sa_ptr != NULL)
	{
		if (sa_ptr->value > max_value)
		{
			max_value = sa_ptr->value;
			index = sa_ptr->index;
		}
		sa_ptr = sa_ptr->next;
	}
	return (index);
}

bool	check_argv2(int argc, char *argv, t_operations *list)
{
	int	i;

	i = 0;
	(void)argc;
	while (argv[i])
	{
		if (!ft_isdigit_ps(argv[i]))
			return (free(list), false);
		i++;
	}
	return (true);
}
