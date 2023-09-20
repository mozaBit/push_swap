/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:52:15 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/20 15:53:12 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Permet de trouver la derniere node dans la stack
*/
t_stack	*return_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

/*
 * Permet de retourner le plus grand chiffre dans la stack
*/
t_stack	*return_first_node(t_stack *stack)
{
	int		i;
	t_stack	*first_node;

	if (!stack)
		return (NULL);
	i = INT_MIN;
	while (stack)
	{
		if (i < stack->value)
		{
			i = stack->value;
			first_node = stack;
		}
		stack = stack->next;
	}
	return (first_node);
}

/*
 * Permer de rajouter une node dans la stack
*/
void	append_to_stack(t_stack **stack, int nb)
{
	t_stack	*last_node;
	t_stack	*new_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->value = nb;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = return_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
