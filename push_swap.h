/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:48:15 by chukim            #+#    #+#             */
/*   Updated: 2022/05/26 13:05:54 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	int				len;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_stack_set
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				pivot1;
	int				pivot2;
	int				len;
}	t_stack_set;

typedef struct s_cnt_a
{
	int	cnt_ra;
	int	cnt_pb;
	int	cnt_rb;
	int	cnt_i;
}	t_cnt_a;

typedef struct s_cnt_b
{
	int	cnt_rb;
	int	cnt_pa;
	int	cnt_ra;
	int	cnt_i;
}	t_cnt_b;

void	preprocessor(char *str, int i, int flag, t_stack *stack);
void	print_main(long long *result, int *flag, int *sign, t_stack *stack);
void	print_other(long long result, int flag, int sign, t_stack *stack);
void	print_error(void);

t_node	*get_new_node(int num);
t_stack	*get_new_stack(void);
int		is_empty(t_stack *stack);
int		is_exist(int num, t_stack *stack);
int		stack_len(t_stack *stack);
int		return_min(int a, int b);

void	print_stack(t_stack *stack);
void	print_stack_duel(t_stack *stack_a, t_stack *stack_b);
void	print_stack_duel_2(t_stack *stack_a, t_stack *stack_b, int cnt);
void	print_op(t_stack *op);
void	print_op_2(int op);
void	opt_op(t_stack *op);

void	push_top(t_stack *stack, t_node *new_node);
void	push_bottom(t_stack *stack, t_node *new_node);

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack, int direction);

void	sa(t_stack *stack, t_stack *operation_set);
void	sb(t_stack *stack, t_stack *operation_set);
void	ss(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	pa(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	pb(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	ra(t_stack *stack, t_stack *operation_set);
void	rb(t_stack *stack, t_stack *operation_set);
void	rr(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	rra(t_stack *stack, t_stack *operation_set);
void	rrb(t_stack *stack, t_stack *operation_set);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);

void	mini_sort_2(t_stack *stack, t_stack *operation_set, char name);
void	sort_3_a_1(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	sort_3_a_2(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	pb_sa_pa(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	sort_3_b_1(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	sort_3_b_2(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	pa_sb_pb(t_stack *stack_a, t_stack *stack_b, t_stack *operation_set);
void	sorting_3(t_stack *stack_a, t_stack *op);
void	sorting_5(t_stack *stack_a, t_stack *stack_b, t_stack *op);
void	sorting_5_2(t_stack *stack_a, t_stack *stack_b, t_stack *op);
void	basic_test(t_stack *stack_a);

int		*stack_to_arr(t_stack *stack, int len);
void	quick_sort(int arr[], int start, int end);
void	swap_arr(int arr[], int i, int j);
void	select_pivot(t_stack *stack, int *pivot1, int *pivot2, int len);
void	cnt_a_init(t_cnt_a *cnt);
void	cnt_b_init(t_cnt_b *cnt);
void	t_stack_init_a(t_stack *stack_a, t_stack *stack_b,
			t_stack_set *set, int len);
void	t_stack_init_b(t_stack *stack_a, t_stack *stack_b,
			t_stack_set *set, int len);

void	a_to_b(t_stack *stack_a, t_stack *stack_b, t_stack *op, int len);
void	a_to_b_2(t_stack_set *set, t_stack *op, t_cnt_a *cnt);
void	a_to_b_3(t_stack *stack_a, t_stack *stack_b, t_stack *op, t_cnt_a *cnt);
void	b_to_a(t_stack *stack_a, t_stack *stack_b, t_stack *op, int len);
void	b_to_a_2(t_stack_set *set, t_stack *op, t_cnt_b *cnt);
void	b_to_a_3(t_stack *stack_a, t_stack *stack_b, t_stack *op, t_cnt_b *cnt);
int		b_to_a_4(t_stack *stack_a, t_stack *stack_b, t_stack *op, int len);

#endif