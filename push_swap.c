/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:10:11 by chukim            #+#    #+#             */
/*   Updated: 2022/05/04 13:10:11 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*op;

	i = 0;
	stack_a = get_new_stack();
	stack_b = get_new_stack();
	op = get_new_stack();
	while (++i < argc)
		preprocessor(argv[i], -1, 0, stack_a);
	basic_test(stack_a);
	if (stack_a->len == 5 || stack_a->len == 3)
	{
		sorting_5(stack_a, stack_b, op);
	}
	else if (stack_a->len == 0)
		return (0);
	else
		a_to_b(stack_a, stack_b, op, stack_a->len);
	opt_op(op);
	print_op(op);
}

void	print_op(t_stack *op)
{
	t_node	*current;

	current = op->bottom;
	while (op->len-- > 0)
	{
		print_op_2(current->val);
		current = current->right;
	}
}

void	print_op_2(int op)
{
	if (op == 0)
		write(1, "sa\n", 3);
	else if (op == 1)
		write(1, "sb\n", 3);
	else if (op == 2)
		write(1, "ss\n", 3);
	else if (op == 3)
		write(1, "pa\n", 3);
	else if (op == 4)
		write(1, "pb\n", 3);
	else if (op == 5)
		write(1, "ra\n", 3);
	else if (op == 6)
		write(1, "rb\n", 3);
	else if (op == 7)
		write(1, "rr\n", 3);
	else if (op == 8)
		write(1, "rra\n", 4);
	else if (op == 9)
		write(1, "rrb\n", 4);
	else if (op == 10)
		write(1, "rrr\n", 4);
}
