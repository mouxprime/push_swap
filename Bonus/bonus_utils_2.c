/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:53:10 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 17:44:09 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"

bool	is_sorted_stack_a_bonus(t_node *stack_a)
{
	t_node	*sa_ptr;

	sa_ptr = stack_a;
	while (sa_ptr->next)
	{
		if (sa_ptr->next->value < sa_ptr->value)
			return (false);
		sa_ptr = sa_ptr->next;
	}
	return (true);
}

int	treat_buf(char *buf, t_node *stack_a, t_node *stack_b, t_operations *list)
{
	if (!buf || !stack_a)
		return (free(buf), end_checker(stack_a, stack_b, list), 0);
	buf[4] = '\0';
	while (buf)
	{
		free(buf);
		buf = get_next_line(0);
		if (check_buf(&stack_a, &stack_b, list, buf) == false)
			return (ft_free(buf, list, stack_a), write(2, "Error\n", 6));
	}
	free(buf);
	if (!stack_a)
		return (1);
	else if (is_sorted_stack_a_bonus(stack_a) == true)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	ft_operations_clear(&list);
	return (0);
}

void	ft_free(char *buf, t_operations *list, t_node *stack_a)
{
	free(buf);
	free(list);
	ft_stackclear(&stack_a);
}
