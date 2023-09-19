/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 08:49:40 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 23:57:01 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
 * Pour voir est-ce qu'on a une erreur de syntax sur notre string
*/
int	error_in_str(char *str)
{
	if (!(*str == '+'
			|| *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+'
			|| *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

/*
 * Permet de liberer le av argument apres assignation par ft_split
 * ---------------------------------------------------------------
*/
void	free_array(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

/*
 * Permet de liberer la stack a en cas d'erreeur
*/
void	free_stack(t_stack **stack)
{
	t_stack		*current;
	t_stack		*temp;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

/*
 * Permet de faire un free en cas d'erreur de syntax
*/

void	free_stuff(t_stack **stack, char **av, bool is_single)
{
	free_stack(stack);
	if (is_single)
		free_array(av);
	write(2, "Error\n", 6);
	exit(1);
}

int	its_repitition(t_stack *stack, int nb)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}
