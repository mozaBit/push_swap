/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:44:22 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 11:53:57 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}


void	stack_init(t_stack **stack, char **av, bool is_single)
{
	int		i;
	long 	nb;

	i = 0;
	while (av[i])
	{
		if (error_in_str(av[i]))
			free_stuff(stack, av, is_single);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN )
			free_stuff(stack, av, is_single);
		if (its_repitition(*stack, (int)nb))
			free_stuff(stack, av, is_single);
		append_to_stack(stack, (int)nb);
		i++;
	}
	if (is_single)
		free_array(av);
}
