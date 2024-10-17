/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:17:03 by mianni            #+#    #+#             */
/*   Updated: 2024/08/17 11:44:37 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operations	*start_operations_list(t_operations **list)
{
	*list = malloc(sizeof(t_operations));
	if (*list == NULL)
		return (*list);
	(*list)->next = NULL;
	(*list)->operation_code = 999;
	return (*list);
}

t_operations	*create_node(int operation_code, t_operations *list)
{
	t_operations	*new_node;
	t_operations	*first_node;

	first_node = list;
	new_node = malloc(sizeof(t_operations));
	if (new_node == NULL)
		return (NULL);
	if (first_node == NULL)
	{
		new_node->next = NULL;
		list = new_node;
	}
	else
	{
		while (first_node->next != NULL)
			first_node = first_node->next;
		first_node->next = new_node;
	}
	new_node->operation_code = operation_code;
	new_node->next = NULL;
	return (new_node);
}

void	translate_operations(t_operations *list)
{
	while (list)
	{
		if (list->operation_code == 0)
			write(1, "pa\n", 3);
		if (list->operation_code == 1)
			write(1, "pb\n", 3);
		if (list->operation_code == 2)
			write(1, "sa\n", 3);
		if (list->operation_code == 3)
			write(1, "sb\n", 3);
		if (list->operation_code == 4 || list->operation_code == 5)
			list = opti_rr(list);
		if (list->operation_code == 6 || list->operation_code == 7)
			list = opti_rrr(list);
		if (list->operation_code == 8)
			write(1, "ss\n", 3);
		list = list->next;
	}
}

t_operations	*opti_rr(t_operations *list)
{
	if (list->next && (list->operation_code == 4
			&& list->next->operation_code == 5))
	{
		write(1, "rr\n", 3);
		return (list->next);
	}
	else if (list->next && (list->operation_code == 5
			&& list->next->operation_code == 4))
	{
		write(1, "rr\n", 3);
		return (list->next);
	}
	else
	{
		if (list->operation_code == 4)
			write(1, "ra\n", 3);
		if (list->operation_code == 5)
			write(1, "rb\n", 3);
	}
	return (list);
}

t_operations	*opti_rrr(t_operations *list)
{
	if (list->next && (list->operation_code == 6
			&& list->next->operation_code == 7))
	{
		write(1, "rrr\n", 4);
		return (list->next);
	}
	else if (list->next && (list->operation_code == 7
			&& list->next->operation_code == 6))
	{
		write(1, "rrr\n", 4);
		return (list->next);
	}
	else
	{
		if (list->operation_code == 6)
			write(1, "rra\n", 4);
		if (list->operation_code == 7)
			write(1, "rrb\n", 4);
	}
	return (list);
}
