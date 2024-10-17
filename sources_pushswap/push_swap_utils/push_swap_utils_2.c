/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 16:43:19 by mianni            #+#    #+#             */
/*   Updated: 2024/08/19 13:22:44 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup_node_data(t_node *node)
{
	node->index = 0;
	node->target = NULL;
	node->next = NULL;
	node->cheapest = 0;
	node->push_cost = 0;
	node->median = false;
}

int	min_value_index(t_node *stack)
{
	int		min_index;
	int		min_value;
	t_node	*ptr;

	min_index = 0;
	min_value = stack->value;
	ptr = stack;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = stack->index;
		}
		stack = stack->next;
	}
	stack = ptr;
	return (min_index);
}

void	push_it_to_top_stack_a(t_node *ptr, t_node **stack, t_operations *list)
{
	int	cost_to_top;
	int	len;
	int	i;

	len = node_len(*stack);
	cost_to_top = define_cost_to_top(ptr, len);
	i = 0;
	if (ptr->index <= (len / 2) && ptr->index != 0)
	{
		while (i < cost_to_top)
		{
			ft_rotate_a(stack, list);
			i++;
		}
	}
	else if (ptr->index != 0)
	{
		i = 0;
		while (i < cost_to_top)
		{
			ft_reverse_rotate_a(stack, list);
			i++;
		}
	}
}

void	push_it_to_top_stack_b(t_node *ptr, t_node **stack, t_operations *list)
{
	int	cost_to_top;
	int	len;
	int	i;

	len = node_len(*stack);
	cost_to_top = define_cost_to_top(ptr, len);
	i = 0;
	if (ptr->index == 1)
		ft_swap_b(stack, list);
	if (ptr->index <= (len / 2) && ptr->index != 0 && ptr->index != 1)
	{
		while (i < cost_to_top)
		{
			ft_rotate_b(stack, list);
			i++;
		}
	}
	else if (ptr->index != 0 && ptr->index != 1)
	{
		while (i < cost_to_top)
		{
			ft_reverse_rotate_b(stack, list);
			i++;
		}
	}
}

int	setup_data(t_node *src, t_node *dest)
{
	t_node	*ptr;
	t_node	*ptr_dest;

	ptr = src;
	ptr_dest = dest;
	while (src)
	{
		define_target(src, dest);
		src = src->next;
	}
	src = ptr;
	dest = ptr_dest;
	define_push_cost(ptr, dest);
	define_cheapest(ptr);
	return (1);
}
