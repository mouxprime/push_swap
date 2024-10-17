/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:00:51 by mianni            #+#    #+#             */
/*   Updated: 2024/08/20 11:54:33 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*first_node(t_node *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

void	ft_stackclear(t_node **lst)
{
	t_node	*tmp;
	t_node	*lsttemp;

	lsttemp = *lst;
	while (lsttemp)
	{
		tmp = (lsttemp)->next;
		free(lsttemp);
		lsttemp = tmp;
	}
	*lst = NULL;
}

void	ft_operations_clear(t_operations **lst)
{
	t_operations	*tmp;
	t_operations	*lsttemp;

	lsttemp = *lst;
	while (lsttemp)
	{
		tmp = (lsttemp)->next;
		free(lsttemp);
		lsttemp = tmp;
	}
	*lst = NULL;
}

void	gerer_push_b2(int median, t_node **stack_b, t_operations *list)
{
	t_node	*sb_ptr;

	sb_ptr = *stack_b;
	if (sb_ptr->value > (median * 0.75))
		ft_rotate_b(stack_b, list);
}

void	gerer_push_b(int median, t_node **stack_b, t_operations *list)
{
	t_node	*sb_ptr;

	sb_ptr = *stack_b;
	if (sb_ptr->value > (median * 1.5))
		ft_rotate_b(stack_b, list);
}
