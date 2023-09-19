/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:38:27 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 19:55:03 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Permet d'avoir la longueur de la stack
*/
int		stack_length(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/*
 * Permet de savoir si la stack est triee
*/
bool	stack_sorted(t_stack *stack)
{
	int		i;
	t_stack	*current;

	if (!stack)
		return (true);
	i = stack->value;
	current = stack->next;
	while (current)
	{
		if (i > current->value)
			return (false);
		i = current->value;
		current = current->next;
	}
	return (true);
}

t_stack	*return_smallest_node(t_stack *stack)
{
	long		i;
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	i = LONG_MAX;
	while (stack)
	{
		if (i > stack->value)
		{
			i = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*return_cheapest_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
