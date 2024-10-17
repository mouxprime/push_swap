/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:46:38 by mianni            #+#    #+#             */
/*   Updated: 2024/08/08 12:19:48 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_utils/push_swap.h"

int	ft_swap(t_node **stack)
{
	t_node	*first_element;
	t_node	*second_element;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first_element = *stack;
	second_element = first_element->next;
	first_element->next = second_element->next;
	if (second_element->next != NULL)
		second_element->next->prev = first_element;
	second_element->prev = NULL;
	second_element->next = first_element;
	first_element->prev = second_element;
	*stack = second_element;
	return (1);
}

int	ft_swap_ss(t_node **stack1, t_node **stack2, t_operations *list)
{
	if (ft_swap(stack1) == 0)
		create_node(-1, list);
	else if (ft_swap(stack2) == 0)
		create_node(-1, list);
	else
		create_node(8, list);
	return (1);
}

int	ft_swap_a(t_node **stack_a, t_operations *list)
{
	if (ft_swap(stack_a) == 0)
		create_node(-1, list);
	else
		create_node(2, list);
	return (1);
}

int	ft_swap_b(t_node **stack_b, t_operations *list)
{
	if (ft_swap(stack_b) == 0)
		create_node(-1, list);
	else
		create_node(3, list);
	return (1);
}
