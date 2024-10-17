/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:07:59 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 17:17:41 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node			*stack_a;
	t_node			*stack_b;
	t_operations	*list;

	list = start_operations_list(&list);
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (free(list), 0);
	if (argc == 2)
	{
		if (check_argv2(argc, argv[1], list) == false)
			return (write(2, "Error\n", 6), 0);
		if (argv[1][0] == '\0')
			return (0);
		argv = ft_split(argv[1], 32);
		if (argv == NULL)
			return (0);
	}
	stack_a = ft_setup_and_check(stack_a, argc, argv, list);
	if (node_len(stack_a) < 6)
		sort_small_size(&stack_a, &stack_b, list);
	else
		algorithm(&stack_a, &stack_b, list);
	return (clear_and_print_operations(stack_a, stack_b, list), 0);
}
