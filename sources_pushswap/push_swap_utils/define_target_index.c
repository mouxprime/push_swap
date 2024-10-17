/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_target_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:58:34 by mianni            #+#    #+#             */
/*   Updated: 2024/08/18 15:29:18 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	define_index(t_node *stack)
{
	int		i;
	t_node	*ptr;

	ptr = stack;
	i = 0;
	while (ptr)
	{
		ptr->index = i;
		ptr = ptr->next;
		i++;
	}
}

int	setup_target_index(t_node *stack_a, t_node *stack_b)
{
	long	diff;
	int		index;
	t_node	*sa_ptr;
	t_node	*sb_ptr;

	diff = LONG_MAX;
	index = 0;
	sa_ptr = stack_a;
	sb_ptr = stack_b;
	while (sa_ptr)
	{
		if (sa_ptr->value > sb_ptr->value && sa_ptr->value < diff)
		{
			diff = sa_ptr->value;
			index = sa_ptr->index;
		}
		sa_ptr = sa_ptr->next;
	}
	sa_ptr = stack_a;
	if (diff == LONG_MAX)
		index = (min_value_index(sa_ptr));
	return (index);
}

void	define_target(t_node *src, t_node *dest)
{
	int		index2;
	t_node	*dest_ptr;
	t_node	*src_ptr;

	dest_ptr = dest;
	src_ptr = src;
	while (src)
	{
		index2 = setup_target_index(dest, src);
		dest_ptr = dest;
		while (dest_ptr->index != index2)
			dest_ptr = dest_ptr->next;
		src->target = dest_ptr;
		src = src->next;
	}
	src = src_ptr;
}

void	define_median_bool(t_node *stack, int median)
{
	while (stack->value != median)
		stack = stack->next;
	stack->median = true;
}

bool	no_more_median(int median, t_node **stack)
{
	t_node	*sa_ptr;

	sa_ptr = *stack;
	while (sa_ptr)
	{
		if (sa_ptr->value > median)
			return (false);
		else
			sa_ptr = sa_ptr->next;
	}
	return (true);
}
