/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:55:43 by mianni            #+#    #+#             */
/*   Updated: 2024/09/09 14:11:47 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	unsigned long int	j;

	j = 0;
	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[start + j] && j < len)
	{
		dest[j] = s[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

bool	is_sorted_stack_a(t_node *stack_a)
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

void	clear_and_print_operations(t_node *stack_a, t_node *stack_b,
		t_operations *list)
{
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	translate_operations(list);
	ft_operations_clear(&list);
}

bool	ft_check(const char *nptr)
{
	int	i;

	i = 0;
	if (nptr[i] == 45 && ft_isdigit_ps(nptr[i + 1]))
		i++;
	if (nptr[i] == 43 && ft_isdigit_ps(nptr[i + 1]))
		i++;
	if (nptr[i] == 34 && nptr[i + 1] == 34)
		return (false);
	while (nptr[i])
	{
		if (!ft_isdigit_ps(nptr[i]))
			return (false);
		i++;
	}
	return (true);
}
