/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:05:29 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 11:05:30 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	push_swap_medium(int *stack, int size)
{
	int		atop;

	atop = partition_insertion(stack, size, next_pivot(0, size, 0));
	top_pos_b(stack, atop, pos_of_biggest(stack, atop));
	if (status(&stack[atop], size - atop) >= ORDERED)
	{
		while (atop > 0)
		{
			top_pos_a(stack, atop, size,
				insert_pos_a(stack, atop, size, stack[atop - 1]));
			pa(&atop);
		}
		top_sml_a(stack, atop, size);
	}
	else
	{
		modify_stack(&stack[atop], size - atop);
		push_swap_small(&stack[atop], size - atop);
		while (atop > 0)
			pa(&atop);
	}
}

int	partition_insertion(int *stack, int size, int pivot)
{
	int		atop;

	atop = 0;
	while (pivot < size - 10)
	{
		while (atop <= pivot && status(&stack[atop], size - atop) < ORDERED)
		{
			if (stack[atop] <= pivot)
			{
				top_pos_b(stack, atop, insert_pos(stack, atop, stack[atop]));
				pb(&atop, size);
			}
			else
				rotate_to_next_a(stack, atop, pivot, size);
		}
		pivot = next_pivot(atop, size, pivot);
	}
	return (atop);
}

void	rotate_to_next_a(int *stack, int atop, int pivot, int size)
{
	int	com;
	int	ra;
	int	rra;

	ra = pos_of_next_a(stack, atop, pivot) - atop;
	rra = size - pos_of_next_a_reverse(stack, pivot, size);
	if (rra < ra - (size - pivot) / 15)
	{
		com = common_rrt_times(stack, atop, pivot, size);
		rrr_n(stack, atop, size, com);
		rra_n(stack, atop, size, rra - com);
	}
	else
	{
		com = common_rt_times(stack, atop, pivot, &ra);
		rr_n(stack, atop, size, com);
		ra_n(stack, atop, size, ra - com);
	}
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

int	common_rrt_times(int *stack, int atop, int pivot, int size)
{
	int	ret;
	int	rrb;
	int	rra;
	int	apos;
	int	bpos;

	apos = pos_of_next_a_reverse(stack, pivot, size);
	rra = size - apos;
	bpos = insert_pos(stack, atop, stack[apos]);
	rrb = bpos + 1;
	ret = ft_min(rra, rrb);
	if (bpos >= atop / 2 && rrb - ret > atop - bpos - 1)
		ret = 0;
	return (ret);
}
