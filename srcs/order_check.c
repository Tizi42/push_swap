/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:03:33 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 11:03:35 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	continuous_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] != i)
			return (0);
		i++;
	}
	return (1);
}

int	continuous_ordered(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] - stack[i + 1] != -1
			&& stack[i] - stack[i + 1] != size - 1)
			return (0);
		i++;
	}
	return (1);
}
