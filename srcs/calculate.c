/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:44:57 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 15:44:58 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_of_smallest(int *stack, int size)
{
	int	pos;

	pos = --size;
	while (size > 0)
	{
		size--;
		if (stack[size] < stack[pos])
			pos = size;
	}
	return (pos);
}

int	pos_of_biggest(int *stack, int size)
{
	int	pos;

	pos = --size;
	while (size > 0)
	{
		size--;
		if (stack[size] > stack[pos])
			pos = size;
	}
	return (pos);
}

int	pos_of_next_a(int *stack, int atop, int pivot)
{
	while (stack[atop] > pivot)
		atop++;
	return (atop);
}

int	pos_of_next_a_reverse(int *stack, int pivot, int size)
{
	size--;
	while (stack[size] > pivot)
		size--;
	return (size);
}

int	next_pivot(int atop, int size, int pivot)
{
	float	a;

	a = size * 0.00875 + 2.625;
	if (size > 100 && size - pivot <= 100)
		a = 3.5;
	if (atop >= pivot)
	{
		if (pivot == (int)(pivot + (size - pivot) / a))
			pivot = size;
		else
			pivot += (size - pivot) / a;
	}
	else
		pivot = size;
	return (pivot);
}
