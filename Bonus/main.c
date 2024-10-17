/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:39:53 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 17:24:07 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_node			*stack_a;
	t_node			*stack_b;
	t_operations	*list;
	char			*buf;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (check_argv2(argc, argv[1], NULL) == false)
			return (write(2, "Error\n", 6), 0);
		if (argv[1][0] == '\0')
			return (0);
		argv = ft_split(argv[1], 32);
		if (argv == NULL)
			return (0);
	}
	stack_a = NULL;
	buf = malloc(5 * sizeof(char));
	list = start_operations_list(&list);
	stack_a = ft_setup_and_check_bonus(stack_a, argc, argv);
	if (stack_a == NULL)
		ft_operations_clear(&list);
	stack_b = NULL;
	treat_buf(buf, stack_a, stack_b, list);
}
