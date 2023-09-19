/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rero_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:37:09 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 13:40:53 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void rero(t_stack **stack)
{
	t_stack	*last_node;
	int		length;

	length = stack_length(*stack);
	if (!stack || !*stack || length < 2)
		return ;
	last_node = return_last_node(*stack);
	last_node->next = *stack;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool print)
{
	rero(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
	rero(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rero(a);
	rero(b);
	if (print)
		write(1, "rrr\n", 4);
}
