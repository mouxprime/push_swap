/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:48:36 by mianni            #+#    #+#             */
/*   Updated: 2024/08/11 14:43:08 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_utils/push_swap.h"

int	ft_reverse_rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*new_last_node;

	if (!(*stack) || !(*stack)->next)
		return (0);
	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	new_last_node = last_node->prev;
	if (new_last_node)
		new_last_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
	last_node->prev = NULL;
	*stack = last_node;
	return (1);
}

int	ft_reverse_rotate_rrr(t_node **stack1, t_node **stack2, t_operations *list)
{
	if (ft_reverse_rotate(stack1) == 0 || ft_reverse_rotate(stack2) == 0)
		create_node(-1, list);
	else
		create_node(10, list);
	return (1);
}

int	ft_reverse_rotate_a(t_node **stack_a, t_operations *list)
{
	if (ft_reverse_rotate(stack_a) == 0)
		create_node(-1, list);
	else
		create_node(6, list);
	return (1);
}

int	ft_reverse_rotate_b(t_node **stack_b, t_operations *list)
{
	if (ft_reverse_rotate(stack_b) == 0)
		create_node(-1, list);
	else
		create_node(7, list);
	return (1);
}
