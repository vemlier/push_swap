/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:20:54 by chukim            #+#    #+#             */
/*   Updated: 2022/10/29 17:49:15 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_5(t_stack *stack_a, t_stack *stack_b, t_stack *op)
{
	int		len;
	int		*arr;
	t_node	*current;

	if (stack_a->len == 3)
	{
		sorting_3(stack_a, op);
		return ;
	}
	len = stack_a->len;
	arr = stack_to_arr(stack_a, len);
	quick_sort(arr, 0, len - 1);
	current = stack_a->top;
	while (len-- > 0)
	{
		if (current->val == arr[0] || current->val == arr[4])
			pb(stack_a, stack_b, op);
		else
			ra(stack_a, op);
		current = stack_a->top;
	}
	sorting_5_2(stack_a, stack_b, op);
}

void	sorting_5_2(t_stack *stack_a, t_stack *stack_b, t_stack *op)
{
	sorting_3(stack_a, op);
	pa(stack_a, stack_b, op);
	if (stack_a->top->val > stack_b->top->val)
	{
		ra(stack_a, op);
		pa(stack_a, stack_b, op);
	}
	else
	{
		pa(stack_a, stack_b, op);
		ra(stack_a, op);
	}
}

void	sorting_3(t_stack *stack_a, t_stack *op)
{
	t_node	*current;

	current = stack_a->top;
	if (current->val > current->left->val
		&& current->val < stack_a->bottom->val)
		sa(stack_a, op);
	else if (current->left->val < current->val
		&& current->left->val > stack_a->bottom->val)
	{
		sa(stack_a, op);
		rra(stack_a, op);
	}
	else if (stack_a->bottom->val < current->val
		&& stack_a->bottom->val > current->left->val)
		ra(stack_a, op);
	else if (stack_a->bottom->val > current->val
		&& stack_a->bottom->val < current->left->val)
	{
		sa(stack_a, op);
		ra(stack_a, op);
	}
	else if (current->val < current->left->val
		&& current->val > stack_a->bottom->val)
		rra(stack_a, op);
}

void	basic_test(t_stack *stack_a)
{
	int		len;
	t_node	*current;

	len = stack_a->len;
	len--;
	current = stack_a->top;
	while (len-- > 0)
	{
		if (current->val > current->left->val)
			return ;
		current = current->left;
	}
	exit(0);
}
