/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:14:26 by chukim            #+#    #+#             */
/*   Updated: 2022/05/26 12:25:11 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(0);
	swap(stack);
	push_top(operation_set, operation);
}

void	sb(t_stack *stack, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(1);
	swap(stack);
	push_top(operation_set, operation);
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(2);
	swap(stack_a);
	swap(stack_b);
	push_top(operation_set, operation);
}

void	pa(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(3);
	push(stack_b, stack_a);
	push_top(operation_set, operation);
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(4);
	push(stack_a, stack_b);
	push_top(operation_set, operation);
}
