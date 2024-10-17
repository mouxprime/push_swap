/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:47:45 by mianni            #+#    #+#             */
/*   Updated: 2024/08/19 11:50:39 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_utils/push_swap.h"

int	ft_rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!(*stack) || !(*stack)->next)
		return (0);
	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	first_node->next = NULL;
	return (1);
}

int	ft_rotate_rr(t_node **stack1, t_node **stack2, t_operations *list)
{
	if (ft_rotate(stack1) == 0)
		create_node(-1, list);
	else if (ft_rotate(stack2) == 0)
		create_node(-1, list);
	else
		create_node(9, list);
	return (1);
}

int	ft_rotate_a(t_node **stack_a, t_operations *list)
{
	if (ft_rotate(stack_a) == 0)
		create_node(-1, list);
	else
		create_node(4, list);
	return (1);
}

int	ft_rotate_b(t_node **stack_b, t_operations *list)
{
	if (ft_rotate(stack_b) == 0)
		create_node(-1, list);
	else
		create_node(5, list);
	return (1);
}
