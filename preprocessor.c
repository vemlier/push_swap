/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessor_h.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chukim <chukim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:10:26 by chukim            #+#    #+#             */
/*   Updated: 2022/05/04 13:10:26 by chukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_main(long long *result, int *flag, int *sign, t_stack *stack)
{
	*result = *result * (long long)(*sign);
	if (*result <= INT_MAX && *result >= INT_MIN
		&& !(is_exist((int)*result, stack)))
	{
		push_bottom(stack, get_new_node((int)*result));
		*result = 0;
		*flag = 0;
		*sign = 1;
	}
	else
		print_error();
}

void	print_other(long long result, int flag, int sign, t_stack *stack)
{
	result = result * (long long)sign;
	if (flag == 1 && !(is_exist((int)result, stack))
		&& (result <= INT_MAX && result >= INT_MIN))
		push_bottom(stack, get_new_node((int)result));
	else if (flag != 0)
		print_error();
}

void	preprocessor(char *str, int i, int flag, t_stack *stack)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (str[++i] != '\0')
	{
		if (flag == 0 && str[i] == '-')
			sign = -1;
		else if (ft_isdigit(str[i]))
		{
			result = result * 10 + (str[i] - 48);
			flag = 1;
		}
		else if (str[i] != ' ')
			print_error();
		else if (flag == 1)
			print_main(&result, &flag, &sign, stack);
	}
	print_other(result, flag, sign, stack);
}
