/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:46:45 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 20:40:20 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	finish_rotation(t_stack **stack, t_stack *above_node, char stack_name)
{
	while (*stack != above_node)
	{
		if (stack_name == 'a')
		{
			if (above_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (above_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack **a,
									t_stack **b,
									t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, true);
	set_current_position(*a);
	set_current_position(*b);
}

static void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest_node(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(a, cheapest_node, 'a');
	finish_rotation(b, cheapest_node->target_node, 'b');
	pa(a, b, true);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*small_node;
	int		length;

	length = stack_length(*a);
	if (length == 5)
		five_algo(a, b);
	else
	{
		while (length > 3)
			pb(b, a, false);
	}
	short_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	small_node = return_smallest_node(*a);
	if (small_node->above_median)
		while (*a != small_node)
			ra(a, true);
	else
		while (*a != small_node)
			rra(a, true);
}
