/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:28:26 by chukim            #+#    #+#             */
/*   Updated: 2022/05/25 10:54:57 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_pivot(t_stack *stack, int *pivot1, int *pivot2, int len)
{
	int	*arr;

	if (len < 2)
	{
		ft_printf("stack is smaller than 2\n");
		return ;
	}
	arr = stack_to_arr(stack, len);
	quick_sort(arr, 0, len - 1);
	*pivot1 = arr[(len / 3) * 2];
	*pivot2 = arr[len / 3];
}

void	mini_sort_2(t_stack *stack, t_stack *operation_set, char name)
{
	t_node	*current;

	current = stack->top;
	if (current->left != NULL)
	{
		if (name == 'a')
		{
			if (current->val > current->left->val)
				sa(stack, operation_set);
		}
		else if (name == 'b')
		{
			if (current->val < current->left->val)
				sb(stack, operation_set);
		}
		else
			print_error();
	}
}

void	sort_3_a_1(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*current;

	if (stack_a->len < 3)
	{
		mini_sort_2(stack_a, operation_set, 'a');
		return ;
	}
	current = stack_a->top;
	if (current->val > current->left->val
		&& current->val < current->left->left->val)
	{
		sa(stack_a, operation_set);
	}
	else if (current->left->val > current->left->left->val
		&& current->left->val < current->val)
	{
		sa(stack_a, operation_set);
		pb(stack_a, stack_b, operation_set);
		sa(stack_a, operation_set);
		pa(stack_a, stack_b, operation_set);
		sa(stack_a, operation_set);
	}
	else
		sort_3_a_2(stack_a, stack_b, operation_set);
}

void	sort_3_a_2(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	t_node	*current;

	current = stack_a->top;
	if (current->left->left->val > current->left->val
		&& current->left->left->val < current->val)
	{
		sa(stack_a, operation_set);
		pb_sa_pa(stack_a, stack_b, operation_set);
	}
	else if (current->left->left->val < current->left->val
		&& current->left->left->val > current->val)
	{
		pb_sa_pa(stack_a, stack_b, operation_set);
	}
	else if (current->val < current->left->val
		&& current->val > current->left->left->val)
	{
		pb_sa_pa(stack_a, stack_b, operation_set);
		sa(stack_a, operation_set);
	}
}

void	pb_sa_pa(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set)
{
	pb(stack_a, stack_b, operation_set);
	sa(stack_a, operation_set);
	pa(stack_a, stack_b, operation_set);
}
