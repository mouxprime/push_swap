/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:24:55 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 17:39:21 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"

t_node	*ft_setup_and_check_bonus(t_node *stack_a, int argc, char **argv)
{
	long	nb;
	int		i;

	nb = 0;
	i = 1;
	(void)argc;
	while (argv[i])
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (ft_stackclear(&stack_a), write(2, "Error\n", 6), NULL);
		if (ft_parsing((const char **)argv) == false)
			return (write(2, "Error\n", 6), NULL);
		nb = ft_atol((const char *)argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (ft_stackclear(&stack_a), write(2, "Error\n", 6), NULL);
		stack_a = ft_create_node(nb, stack_a);
		i++;
	}
	clear_argv(argv, argc);
	if (ft_check_double(stack_a) == false)
		return (ft_stackclear(&stack_a), write(2, "Error\n", 6), NULL);
	return (stack_a);
}

void	do_operations(t_node **stack_a, t_node **stack_b, t_operations *list,
		char *buf)
{
	if (buf == NULL || stack_a == NULL || stack_b == NULL)
		return ;
	if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		ft_push_b(stack_a, stack_b, list);
	if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		ft_push_a(stack_b, stack_a, list);
	if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		ft_swap_a(stack_a, list);
	if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		ft_swap_b(stack_b, list);
	if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		ft_rotate_a(stack_a, list);
	if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		ft_rotate_b(stack_b, list);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		ft_rotate_rr(stack_a, stack_b, list);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && buf[3] == '\n')
		ft_reverse_rotate_a(stack_a, list);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && buf[3] == '\n')
		ft_reverse_rotate_b(stack_b, list);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && buf[3] == '\n')
		ft_reverse_rotate_rrr(stack_a, stack_b, list);
}

bool	check_buf(t_node **stack_a, t_node **stack_b, t_operations *list,
		char *buf)
{
	if (buf == NULL || stack_a == NULL || stack_b == NULL || buf[0] == 0)
		return (true);
	if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\n')
		return (ft_push_b(stack_a, stack_b, list), true);
	if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\n')
		return (ft_push_a(stack_b, stack_a, list), true);
	if (buf[0] == 's' && buf[1] == 'a' && buf[2] == '\n')
		return (ft_swap_a(stack_a, list), true);
	if (buf[0] == 's' && buf[1] == 'b' && buf[2] == '\n')
		return (ft_swap_b(stack_b, list), true);
	if (buf[0] == 'r' && buf[1] == 'a' && buf[2] == '\n')
		return (ft_rotate_a(stack_a, list), true);
	if (buf[0] == 'r' && buf[1] == 'b' && buf[2] == '\n')
		return (ft_rotate_b(stack_b, list), true);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == '\n')
		return (ft_rotate_rr(stack_a, stack_b, list), true);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a' && buf[3] == '\n')
		return (ft_reverse_rotate_a(stack_a, list), true);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b' && buf[3] == '\n')
		return (ft_reverse_rotate_b(stack_b, list), true);
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r' && buf[3] == '\n')
		return (ft_reverse_rotate_rrr(stack_a, stack_b, list), true);
	else
		return (false);
}

void	write_error_and_clear(t_node **stack)
{
	ft_stackclear(stack);
	write(2, "Error\n", 6);
}

void	end_checker(t_node *stack_a, t_node *stack_b, t_operations *list)
{
	if (!stack_a)
		return ;
	else if (is_sorted_stack_a_bonus(stack_a) == true)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	ft_operations_clear(&list);
}
