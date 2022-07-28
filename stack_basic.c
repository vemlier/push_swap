/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:39:02 by chukim            #+#    #+#             */
/*   Updated: 2022/05/25 10:19:49 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_exist(int num, t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		if (current->val == num)
			return (1);
		current = current->left;
	}
	return (0);
}

void	swap(t_stack *stack)
{
	t_node	*current;

	if (stack_len(stack) >= 2)
	{
		current = stack->top;
		if (current->left->left != NULL)
			current->left->left->right = current;
		else
			stack->bottom = current;
		stack->top = current->left;
		current->left = stack->top->left;
		current->right = stack->top;
		stack->top->left = current;
		stack->top->right = NULL;
	}
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*current;

	if (from->top != NULL)
	{
		current = from->top;
		if (current->left == NULL)
			from->bottom = NULL;
		from->top = current->left;
		push_top(to, current);
		from->len--;
	}
}

void	rotate(t_stack *stack, int direction)
{
	t_node	*current;

	if (stack->len <= 1)
		return ;
	if (direction == 1)
	{
		current = stack->top;
		stack->top = current->left;
		stack->top->right = NULL;
		push_bottom(stack, current);
	}
	else if (direction == -1)
	{
		current = stack->bottom;
		stack->bottom = current->right;
		stack->bottom->left = NULL;
		push_top(stack, current);
	}
	stack->len--;
}
