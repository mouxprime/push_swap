/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_median_cheapest.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:23:12 by mianni            #+#    #+#             */
/*   Updated: 2024/08/18 15:01:55 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	define_median(t_node *stack)
{
	int		*stack_tab;
	int		len_node;
	int		i;
	int		median;
	t_node	*ptr;

	len_node = node_len(stack);
	median = 0;
	ptr = stack;
	stack_tab = malloc(sizeof(int) * len_node + 1);
	if (!stack_tab)
		return (0);
	i = 0;
	while (stack)
	{
		stack_tab[i] = stack->value;
		i++;
		stack = stack->next;
	}
	median = median_return(stack_tab, len_node);
	define_median_bool(ptr, median);
	return (median);
}

int	median_return(int *stack_tab, int node_len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < node_len)
	{
		j = 0;
		while (j < node_len)
		{
			if (stack_tab[i] < stack_tab[j])
			{
				tmp = stack_tab[i];
				stack_tab[i] = stack_tab[j];
				stack_tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	tmp = stack_tab[node_len / 2];
	return (free(stack_tab), tmp);
}

int	define_cost_to_top(t_node *stack, int len)
{
	int	cost;

	cost = 0;
	if (stack->index <= (len / 2))
		cost = stack->index;
	else
		cost = len - stack->index;
	return (cost);
}

void	define_push_cost(t_node *src, t_node *dest)
{
	int		push_cost;
	int		p2;
	t_node	*ptr;
	int		len;
	int		len2;

	ptr = src;
	len = node_len(src);
	len2 = node_len(dest);
	while (ptr)
	{
		push_cost = define_cost_to_top(ptr, len);
		p2 = define_cost_to_top(ptr->target, len2);
		push_cost = push_cost + p2;
		ptr->push_cost = push_cost;
		ptr = ptr->next;
	}
	ptr = src;
}

void	define_cheapest(t_node *src)
{
	int		diff;
	int		index;
	t_node	*src_ptr;

	diff = src->push_cost;
	index = 0;
	src_ptr = src;
	while (src_ptr)
	{
		if (src_ptr->push_cost < diff)
		{
			index = src_ptr->index;
			diff = src_ptr->push_cost;
		}
		src_ptr = src_ptr->next;
	}
	src_ptr = src;
	while (src_ptr)
	{
		if (src_ptr->index == index)
			src_ptr->cheapest = 1;
		else
			src_ptr->cheapest = 0;
		src_ptr = src_ptr->next;
	}
}
