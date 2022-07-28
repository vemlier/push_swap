/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_swap2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:30:02 by chukim            #+#    #+#             */
/*   Updated: 2022/05/26 12:25:11 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(5);
	rotate(stack, 1);
	push_top(operation_set, operation);
}

void	rb(t_stack *stack, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(6);
	rotate(stack, 1);
	push_top(operation_set, operation);
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(7);
	rotate(stack_a, 1);
	rotate(stack_b, 1);
	push_top(operation_set, operation);
}

void	rra(t_stack *stack, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(8);
	rotate(stack, -1);
	push_top(operation_set, operation);
}

void	rrb(t_stack *stack, t_stack *operation_set)
{
	t_node	*operation;

	operation = get_new_node(9);
	rotate(stack, -1);
	push_top(operation_set, operation);
}
