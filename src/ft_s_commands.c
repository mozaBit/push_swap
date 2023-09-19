/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:16:22 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/20 01:41:46 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack **stack)
{
	int		len;

	len = stack_length(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	len = stack_length(*stack);
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
