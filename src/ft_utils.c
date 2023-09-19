/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:38:27 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 13:15:30 by bmetehri         ###   ########.fr       */
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
