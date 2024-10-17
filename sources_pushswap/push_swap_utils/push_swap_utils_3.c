/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:22:04 by mianni            #+#    #+#             */
/*   Updated: 2024/08/21 18:16:04 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack_a(t_node **stack_a, t_operations *list)
{
	t_node	*sa_ptr;

	sa_ptr = *stack_a;
	while (sa_ptr->next)
		sa_ptr = sa_ptr->next;
	if (sa_ptr->value < sa_ptr->prev->value)
		ft_reverse_rotate_a(stack_a, list);
	sa_ptr = *stack_a;
	if (sa_ptr->next->value < sa_ptr->value)
		ft_rotate_a(stack_a, list);
}

void	sort_small_size(t_node **stack_a, t_node **stack_b, t_operations *list)
{
	int	len;

	len = node_len(*stack_a);
	if (len == 3)
		sort_three(stack_a, list);
	if (len == 4 || len == 5)
		sort_four_five(stack_a, stack_b, list);
	if (len == 1)
		return ;
	if (len == 2)
	{
		if ((*stack_a)->value < (*stack_a)->next->value)
			return ;
		else
			ft_swap_a(stack_a, list);
	}
}

void	sort_three(t_node **stack, t_operations *list)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = *stack;
	b = a->next;
	c = b->next;
	if (a->value > b->value && b->value > c->value)
	{
		ft_swap_a(stack, list);
		ft_reverse_rotate_a(stack, list);
	}
	else if (a->value > c->value && c->value > b->value)
		ft_rotate_a(stack, list);
	else if (b->value > a->value && a->value > c->value)
		ft_reverse_rotate_a(stack, list);
	else if (b->value > c->value && c->value > a->value)
	{
		ft_swap_a(stack, list);
		ft_rotate_a(stack, list);
	}
	else if (c->value > a->value && a->value > b->value)
		ft_swap_a(stack, list);
}

void	sort_four_five(t_node **stack_a, t_node **stack_b, t_operations *list)
{
	int	len;
	int	i;

	len = node_len(*stack_a);
	if (len == 5)
		ft_push_b(stack_a, stack_b, list);
	ft_push_b(stack_a, stack_b, list);
	sort_three(stack_a, list);
	define_index(*stack_a);
	while (node_len(*stack_b) > 0)
		push_to_a(stack_b, stack_a, list);
	define_index(*stack_a);
	i = min_value_index(*stack_a);
	while (i > 0)
	{
		ft_rotate_a(stack_a, list);
		i--;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
