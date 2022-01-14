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

int	common_rt_times(int *stack, int atop, int pivot, int *ra)
{
	int	ret;
	int	rb;
	int	apos;
	int	bpos;

	apos = pos_of_next_a(stack, atop, pivot);
	*ra = apos - atop;
	bpos = insert_pos(stack, atop, stack[apos]);
	rb = atop - bpos - 1;
	ret = ft_min(*ra, rb);
	if (bpos < atop / 2 && rb - ret >= bpos + 1)
		ret = 0;
	return (ret);
}

int	pos_of_next_a_r(int *stack, int pivot, int size)
{
	size--;
	while (stack[size] > pivot)
		size--;
	return (size);
}

int	common_rrt_times(int *stack, int atop, int pivot, int *rra, int size)
{
	int	ret;
	int	rrb;
	int	apos;
	int	bpos;

	apos = pos_of_next_a_r(stack, pivot, size);
	*rra = size - apos;
	bpos = insert_pos(stack, atop, stack[apos]);
	rrb = bpos + 1;
	ret = ft_min(*rra, rrb);
	if (bpos >= atop / 2 && rrb - ret > atop - bpos - 1)
		ret = 0;
	return (ret);
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

int	reverse(int *stack, int atop, int size, int pivot)
{
	int	n;
	int	i;
	int	new_pivot;

	n = 0;
	i = atop;
	new_pivot = next_pivot(atop, size, pivot);
	while (i <= (size - atop)  * 3 / 3)
	{
		if (stack[i] <= new_pivot)
			n++;
		i++;
	}
	if (n < (new_pivot - pivot) / 2)
	{
//		printf("yes new pivot = %i, pivot = %i, n :%i\n", new_pivot, pivot, n);
		return (1);
	}
//	printf("no: new pivot = %i, pivot = %i, n :%i\n", new_pivot, pivot, n);
	return (0);
}
