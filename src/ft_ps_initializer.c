/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:17:46 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/20 16:05:10 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_current_position(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	if (NULL == stack)
		return ;
	middle = stack_length(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= middle)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	i;

	while (b)
	{
		i = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->value > b->value && current->value < i)
			{
				i = current->value;
				target = current;
			}
			current = current->next;
		}
		if (i == LONG_MAX)
			b->target_node = return_smallest_node(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	a_length;
	int	b_length;

	a_length = stack_length(a);
	b_length = stack_length(b);
	while (b)
	{
		b->push_cost = b->position;
		if (!(b->above_median))
			b->push_cost = b_length - b->position;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->position;
		else
			b->push_cost += a_length - b->target_node->position;
		b = b->next;
	}
}

static void	set_cheap_node(t_stack *b)
{
	long	i;
	t_stack	*cheap_node;

	if (!b)
		return ;
	i = LONG_MAX;
	while (b)
	{
		if (b->push_cost < i)
		{
			i = b->push_cost;
			cheap_node = b;
		}
		b = b->next;
	}
	cheap_node->cheapest = true;
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheap_node(b);
}
