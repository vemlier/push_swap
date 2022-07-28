/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:48:57 by chukim            #+#    #+#             */
/*   Updated: 2022/05/25 15:10:29 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a(t_stack *stack_a, t_stack *stack_b, t_stack *op, int len)
{
	t_cnt_b		*cnt;
	t_stack_set	*set;

	if (b_to_a_4(stack_a, stack_b, op, len) == 1)
		return ;
	cnt = (t_cnt_b *)malloc(sizeof(t_cnt_b));
	cnt_b_init(cnt);
	set = (t_stack_set *)malloc(sizeof(t_stack_set));
	t_stack_init_b(stack_a, stack_b, set, len);
	b_to_a_2(set, op, cnt);
	a_to_b(stack_a, stack_b, op, cnt->cnt_pa - cnt->cnt_ra);
	b_to_a_3(stack_a, stack_b, op, cnt);
	a_to_b(stack_a, stack_b, op, cnt->cnt_ra);
	b_to_a(stack_a, stack_b, op, cnt->cnt_rb);
}

void	b_to_a_2(t_stack_set *set, t_stack *op, t_cnt_b *cnt)
{
	t_node	*current;

	current = set->stack_b->top;
	while (set->len-- > 0)
	{
		if (current->val < set->pivot2)
		{
			rb(set->stack_b, op);
			cnt->cnt_rb++;
		}
		else
		{
			pa(set->stack_a, set->stack_b, op);
			cnt->cnt_pa++;
			if (current->val < set->pivot1)
			{
				ra(set->stack_a, op);
				cnt->cnt_ra++;
			}
		}
		current = set->stack_b->top;
	}
}

void	b_to_a_3(t_stack *stack_a, t_stack *stack_b, t_stack *op, t_cnt_b *cnt)
{
	int	len;

	if (cnt->cnt_ra >= cnt->cnt_rb)
	{
		len = return_min(cnt->cnt_ra, cnt->cnt_rb);
		cnt->cnt_i = cnt->cnt_ra - len;
		while (len-- > 0)
			rrr(stack_a, stack_b, op);
		while (cnt->cnt_i-- > 0)
			rra(stack_a, op);
	}
	else
	{
		len = return_min(cnt->cnt_ra, cnt->cnt_rb);
		cnt->cnt_i = cnt->cnt_rb - len;
		while (len-- > 0)
			rrr(stack_a, stack_b, op);
		while (cnt->cnt_i-- > 0)
			rrb(stack_b, op);
	}
}

int	b_to_a_4(t_stack *stack_a, t_stack *stack_b, t_stack *op, int len)
{
	if (len == 3)
	{
		sort_3_b_1(stack_a, stack_b, op);
		pa(stack_a, stack_b, op);
		pa(stack_a, stack_b, op);
		pa(stack_a, stack_b, op);
		return (1);
	}
	else if (len == 2)
	{
		sort_3_b_1(stack_a, stack_b, op);
		pa(stack_a, stack_b, op);
		pa(stack_a, stack_b, op);
		return (1);
	}
	else if (len == 1)
	{
		pa(stack_a, stack_b, op);
		return (1);
	}
	else if (len < 1)
		return (1);
	return (0);
}

void	t_stack_init_b(t_stack *stack_a, t_stack *stack_b,
		t_stack_set *set, int len)
{
	set->stack_a = stack_a;
	set->stack_b = stack_b;
	set->len = len;
	select_pivot(stack_b, &(set->pivot1), &(set->pivot2), len);
}
