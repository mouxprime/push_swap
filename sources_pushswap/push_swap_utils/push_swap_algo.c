/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:23:10 by mianni            #+#    #+#             */
/*   Updated: 2024/08/26 16:45:11 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_node **stack_a, t_node **stack_b, t_operations *list)
{
	int		median;
	t_node	*sa_ptr;
	int		i;

	sa_ptr = *stack_a;
	median = define_median(sa_ptr);
	sa_ptr = *stack_a;
	median_sup(median, stack_a, stack_b, list);
	median_inf(median, stack_a, stack_b, list);
	sort_three(stack_a, list);
	push_to_a(stack_b, stack_a, list);
	sa_ptr = *stack_a;
	i = min_value_index(*stack_a) + 1;
	while (sa_ptr->index != i && sa_ptr->next)
		sa_ptr = sa_ptr->next;
	push_it_to_top_stack_a(sa_ptr, stack_a, list);
	check_stack_a(stack_a, list);
}

void	median_inf(int median, t_node **stack_a, t_node **stack_b,
		t_operations *list)
{
	t_node	*sa_ptr;

	sa_ptr = *stack_a;
	median = median * 0.75;
	while (no_more_median(median, stack_a) == false && node_len(*stack_a) > 3)
	{
		sa_ptr = *stack_a;
		if (sa_ptr->value >= median)
		{
			ft_push_b(stack_a, stack_b, list);
			gerer_push_b(median, stack_b, list);
		}
		else
			ft_rotate_a(stack_a, list);
	}
	while (node_len(*stack_a) > 3)
		ft_push_b(stack_a, stack_b, list);
}

void	median_sup(int median, t_node **stack_a, t_node **stack_b,
		t_operations *list)
{
	t_node	*sa_ptr;

	sa_ptr = *stack_a;
	while (no_more_median(median, stack_a) == false)
	{
		sa_ptr = *stack_a;
		if (sa_ptr->value > median)
		{
			ft_push_b(stack_a, stack_b, list);
			gerer_push_b(median, stack_b, list);
		}
		else
			ft_rotate_a(stack_a, list);
	}
	sa_ptr = *stack_a;
}

void	push_to_a(t_node **stack_b, t_node **stack_a, t_operations *list)
{
	t_node	*sa_ptr;
	t_node	*sb_ptr;

	sa_ptr = *stack_a;
	sb_ptr = *stack_b;
	while (node_len(*stack_b) > 0)
	{
		sb_ptr = (*stack_b);
		define_index(*stack_b);
		define_index(*stack_a);
		setup_data(*stack_b, *stack_a);
		while (sb_ptr->cheapest != 1)
			sb_ptr = sb_ptr->next;
		(*stack_b) = first_node(*stack_b);
		(*stack_a) = first_node(*stack_a);
		sa_ptr = sb_ptr->target;
		push_it_to_top_stack_b(sb_ptr, stack_b, list);
		push_it_to_top_stack_a(sa_ptr, stack_a, list);
		if (sa_ptr->index == 0 && sb_ptr->index == 0)
			ft_push_a(stack_b, stack_a, list);
	}
}
