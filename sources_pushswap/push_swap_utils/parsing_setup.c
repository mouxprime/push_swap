/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:51:39 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 14:16:02 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_argv(char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc != 2)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

bool	ft_parsing(const char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 12)
			return (false);
		if (!ft_check(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_double(t_node *stack_a)
{
	t_node	*stack;
	t_node	*temp;

	temp = stack_a;
	stack = temp->next;
	while (temp)
	{
		while (stack)
		{
			if ((temp->value == stack->value) && stack != temp)
			{
				return (false);
			}
			else
				stack = stack->next;
		}
		temp = temp->next;
		stack = temp;
	}
	return (true);
}

t_node	*ft_create_node(int value, t_node *stack)
{
	t_node	*node;
	t_node	*first_node;

	first_node = stack;
	node = NULL;
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	if (first_node == NULL)
	{
		node->prev = NULL;
		node->next = NULL;
		stack = node;
	}
	else
	{
		while (first_node->next != NULL)
			first_node = first_node->next;
		node->prev = first_node;
		first_node->next = node;
	}
	node->value = value;
	setup_node_data(node);
	return (stack);
}

t_node	*ft_setup_and_check(t_node *stack_a, int argc, char **argv,
		t_operations *list)
{
	long	nb;
	int		i;

	nb = 0;
	i = 1;
	(void)argc;
	(void)list;
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
	if (is_sorted_stack_a(stack_a))
		return (ft_stackclear(&stack_a), NULL);
	return (stack_a);
}
