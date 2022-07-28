/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:55:46 by chukim            #+#    #+#             */
/*   Updated: 2022/05/25 11:28:32 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_b_1(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*current;

	if (stack_b->len < 3)
	{
		mini_sort_2(stack_b, operation_set, 'b');
		return ;
	}
	current = stack_b->top;
	if (current->val > current->left->val
		&& current->val < current->left->left->val)
	{
		pa_sb_pb(stack_a, stack_b, operation_set);
		sb(stack_b, operation_set);
	}
	else if (current->left->val < current->left->left->val
		&& current->left->val > current->val)
	{
		sb(stack_b, operation_set);
		pa_sb_pb(stack_a, stack_b, operation_set);
		sb(stack_b, operation_set);
	}
	else
		sort_3_b_2(stack_a, stack_b, operation_set);
}

void	sort_3_b_2(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*current;

	current = stack_b->top;
	if (current->left->left->val > current->left->val
		&& current->left->left->val < current->val)
	{
		pa_sb_pb(stack_a, stack_b, operation_set);
	}
	else if (current->left->left->val < current->left->val
		&& current->left->left->val > current->val)
	{
		sb(stack_b, operation_set);
		pa_sb_pb(stack_a, stack_b, operation_set);
	}
	else if (current->val < current->left->val
		&& current->val > current->left->left->val)
	{
		sb(stack_b, operation_set);
	}
}

void	pa_sb_pb(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	pa(stack_a, stack_b, operation_set);
	sb(stack_b, operation_set);
	pb(stack_a, stack_b, operation_set);
}
