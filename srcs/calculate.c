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
