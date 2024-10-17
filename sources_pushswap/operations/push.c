/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:49:36 by mianni            #+#    #+#             */
/*   Updated: 2024/08/08 13:01:15 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_utils/push_swap.h"

t_node	*ft_push(t_node **source, t_node **destination)
{
	t_node	*top;

	if (*source == NULL)
		return (NULL);
	top = *source;
	*source = (*source)->next;
	if (*source != NULL)
		(*source)->prev = NULL;
	top->next = *destination;
	if (*destination != NULL)
		(*destination)->prev = top;
	*destination = top;
	return (top);
}

t_node	**ft_push_a(t_node **stack_b, t_node **stack_a, t_operations *list)
{
	t_node	*new_top;

	new_top = ft_push(stack_b, stack_a);
	if (new_top == NULL)
		create_node(-1, list);
	else
		create_node(0, list);
	stack_a = &new_top;
	return (stack_a);
}

t_node	**ft_push_b(t_node **stack_a, t_node **stack_b, t_operations *list)
{
	t_node	*new_top;

	new_top = ft_push(stack_a, stack_b);
	if (new_top == NULL)
		create_node(-1, list);
	else
		create_node(1, list);
	stack_b = &new_top;
	return (stack_b);
}
