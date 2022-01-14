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

int	*intdup(int *array, int size)
{
	int	*cp;
	int	n;

	cp = ft_malloc(sizeof(int) * size);
	n = 0;
	while (n < size)
	{
		cp[n] = array[n];
		n++;
	}
	return (cp);
}

int	status(int *stack, int size)
{
	int	*cp;
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			n++;
		if (n >= 2)
			return (0);
		i++;
	}
	if (n == 1)
	{
		i = 0;
		cp = intdup(stack, size);
		if (continuous_ordered(modify_stack(cp, size), size))
			i = ORDERED;
		free(cp);
		return (i);
	}
	else
		return (SORTED);
}

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
