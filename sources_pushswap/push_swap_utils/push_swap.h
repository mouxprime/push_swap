/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:10:22 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 15:29:35 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "limits.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int					value;
	int					index;
	int					push_cost;
	int					cheapest;
	bool				median;
	struct s_node		*next;
	struct s_node		*prev;
	struct s_node		*target;
}						t_node;

typedef struct s_operations
{
	int					operation_code;
	struct s_operations	*next;
}						t_operations;

void					print_operations(t_operations *list);

t_node					**ft_push_a(t_node **stack_b, t_node **stack_a,
							t_operations *list);

t_node					**ft_push_b(t_node **stack_a, t_node **stack_b,
							t_operations *list);

int						ft_swap_a(t_node **stack_a, t_operations *list);

int						ft_swap_b(t_node **stack_b, t_operations *list);

int						ft_swap_ss(t_node **stack1, t_node **stack2,
							t_operations *list);

int						ft_rotate_a(t_node **stack_a, t_operations *list);

int						ft_rotate_b(t_node **stack_b, t_operations *list);

int						ft_rotate_rr(t_node **stack1, t_node **stack2,
							t_operations *list);

int						ft_reverse_rotate_a(t_node **stack_a,
							t_operations *list);

int						ft_reverse_rotate_b(t_node **stack_b,
							t_operations *list);

int						ft_reverse_rotate_rrr(t_node **stack1, t_node **stack2,
							t_operations *list);

bool					ft_parsing(const char **argv);

long					ft_atol(const char *nptr);

t_node					*ft_create_node(int value, t_node *stack);

t_operations			*create_node(int operation_code, t_operations *stack);

int						ft_printf(const char *type, ...);

bool					ft_isdigit_ps(int c);

t_node					*ft_setup_and_check(t_node *stack_a, int argc,
							char **argv, t_operations *list);

void					define_index(t_node *stack);

int						node_len(t_node *stack);

int						define_median(t_node *stack);

int						median_return(int *stack_tab, int node_len);

void					setup_node_data(t_node *node);

void					push_it_to_top_stack_a(t_node *ptr, t_node **stack,
							t_operations *list);

void					push_it_to_top_stack_b(t_node *ptr, t_node **stack,
							t_operations *list);

int						min_value_index(t_node *stack);

void					define_push_cost(t_node *src, t_node *dest);

void					define_cheapest(t_node *src);

int						setup_data(t_node *src, t_node *dest);

void					define_median_bool(t_node *stack, int median);

int						define_cost_to_top(t_node *stack, int len);

t_operations			*start_operations_list(t_operations **list);

void					define_target(t_node *src, t_node *dest);

int						find_max_value(t_node *stack);

void					check_stack_a(t_node **stack_a, t_operations *list);

void					push_to_a(t_node **stack_b, t_node **stack_a,
							t_operations *list);

void					translate_operations(t_operations *list);

t_node					*first_node(t_node *stack);

void					median_sup(int median, t_node **stack_a,
							t_node **stack_b, t_operations *list);

void					gerer_push_b(int median, t_node **stack_b,
							t_operations *list);

bool					no_more_median(int median, t_node **stack);

void					algorithm(t_node **stack_a, t_node **stack_b,
							t_operations *list);

void					median_inf(int median, t_node **stack_a,
							t_node **stack_b, t_operations *list);

void					sort_three(t_node **stack, t_operations *list);

void					sort_four_five(t_node **stack_a, t_node **stack_b,
							t_operations *list);

void					sort_small_size(t_node **stack_a, t_node **stack_b,
							t_operations *list);

t_operations			*opti_rr(t_operations *list);

t_operations			*opti_rrr(t_operations *list);

void					ft_stackclear(t_node **lst);

size_t					ft_strlen(const char *str);

void					ft_operations_clear(t_operations **lst);

bool					ft_check_double(t_node *stack_a);

bool					is_sorted_stack_a(t_node *stack_a);

char					**ft_split(char const *s, char c);

char					**ft_call_split(t_node *stack_a, char **argv);

void					clear_argv(char **argv, int argc);

char					*ft_substr(char const *s, unsigned int start,
							size_t len);

void					print_lista(t_node **stack_a);

void					clear_and_print_operations(t_node *stack_a,
							t_node *stack_b, t_operations *list);

bool					ft_check(const char *nptr);

bool					check_argv2(int argc, char *argv, t_operations *list);

int						call_split(int i, char **argv, t_operations *list);

int						check_split(char **argv, t_operations *list);

bool					check_argv(int argc, char *argv, t_operations *list);

#endif
