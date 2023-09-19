/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:52:15 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 12:03:33 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Permet de trouver la derniere node dans la stack
*/
t_stack	*return_last_node(t_stack *node)
{
	if (NULL == node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
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
		last_node = return_lst_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
