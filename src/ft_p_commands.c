/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:44:32 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/20 00:45:41 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*new_node;

	if (!*src)
		return ;
	new_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new_node->prev = NULL;
	if (!*dst)
	{
		*dst = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dst;
		new_node->next->prev = new_node;
		*dst = new_node;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
