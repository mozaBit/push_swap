/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:25:07 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/20 00:46:07 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	short_sort(t_stack **stack)
{
	t_stack	*first_node;

	first_node = return_first_node(*stack);
	if (*stack == first_node)
		ra(stack, true);
	else if ((*stack)->next == first_node)
		rra(stack, true);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, true);
}

void	five_algo(t_stack **a, t_stack **b)
{
	while (stack_length(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, return_smallest_node(*a), 'a');
		pb(b, a, true);
	}
}
