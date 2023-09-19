/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 07:55:22 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/19 20:36:17 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				position;
	int				last_index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

/*
 * Error handling
*/
int		error_in_str(char *str);
void	free_stuff(t_stack **stack, char **av, bool is_single);
void	free_array(char **av);
void	free_stack(t_stack **stack);
int		its_repitition(t_stack *stack, int nb);

/*
 * Stack Handling
*/
void	stack_init(t_stack **stack, char **av, bool is_single);
void	append_to_stack(t_stack **stack, int nb);
t_stack	*return_last_node(t_stack *node);
t_stack	*return_first_node(t_stack *stack);

/*
 * Utils
*/
char	**ft_split(const char *s, char c);
int		stack_length(t_stack *stack);
bool	stack_sorted(t_stack *stack);
t_stack	*return_smallest_node(t_stack *stack);
void	set_current_position(t_stack *stack);

/*
 * Algorithms
*/
void	short_sort(t_stack **a);
void	init_nodes(t_stack *a, t_stack *b);
void	five_algo(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **stack, t_stack *above_node, char stack_name);
t_stack	*return_cheapest_node(t_stack *stack);
void	push_swap(t_stack **a, t_stack **b);

/*
 * Commands
*/

void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

#endif
