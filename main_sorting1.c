/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:02:21 by chukim            #+#    #+#             */
/*   Updated: 2022/05/26 14:19:19 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *op, int len)
{
	t_cnt_a		*cnt;
	t_stack_set	*set;

	if (len <= 3)
	{
		sort_3_a_1(stack_a, stack_b, op);
		return ;
	}
	cnt = (t_cnt_a *)malloc(sizeof(t_cnt_a));
	cnt_a_init(cnt);
	set = (t_stack_set *)malloc(sizeof(t_stack_set));
	t_stack_init_a(stack_a, stack_b, set, len);
	print_stack_duel(stack_a, stack_b);
	a_to_b_2(set, op, cnt);
	print_stack_duel(stack_a, stack_b);
	a_to_b_3(stack_a, stack_b, op, cnt);
}

void	a_to_b_2(t_stack_set *set, t_stack *op, t_cnt_a *cnt)
{
	t_node	*current;

	current = set->stack_a->top;
	while (set->len-- > 0)
	{
		if (current->val >= set->pivot1)
		{
			ra(set->stack_a, op);
			cnt->cnt_ra++;
		}
		else
		{
			pb(set->stack_a, set->stack_b, op);
			cnt->cnt_pb++;
			if (current->val >= set->pivot2)
			{
				rb(set->stack_b, op);
				cnt->cnt_rb++;
			}
		}
		current = set->stack_a->top;
	}
}

void	a_to_b_3(t_stack *stack_a, t_stack *stack_b, t_stack *op, t_cnt_a *cnt)
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
	a_to_b(stack_a, stack_b, op, cnt->cnt_ra);
	b_to_a(stack_a, stack_b, op, cnt->cnt_rb);
	b_to_a(stack_a, stack_b, op, cnt->cnt_pb - cnt->cnt_rb);
}

void	t_stack_init_a(t_stack *stack_a, t_stack *stack_b,
		t_stack_set *set, int len)
{
	set->stack_a = stack_a;
	set->stack_b = stack_b;
	set->len = len;
	select_pivot(stack_a, &(set->pivot1), &(set->pivot2), len);
}
