/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:34:36 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 17:45:17 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../sources_pushswap/push_swap_utils/push_swap.h"
# include "limits.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_node	*ft_setup_and_check_bonus(t_node *stack_a, int argc, char **argv);

void	do_operations(t_node **stack_a, t_node **stack_b, t_operations *list,
			char *buf);

bool	is_sorted_stack_a_bonus(t_node *stack_a);

void	translate_operations_bonus(t_operations *list);

void	end_checker(t_node *stack_a, t_node *stack_b, t_operations *list);

void	write_error_and_clear(t_node **stack);

bool	check_buf(t_node **stack_a, t_node **stack_b, t_operations *list,
			char *buf);

int		treat_buf(char *buf, t_node *stack_a, t_node *stack_b,
			t_operations *list);

bool	check_argv2(int argc, char *argv, t_operations *list);

void	ft_free(char *buf, t_operations *list, t_node *stack_a);

#endif