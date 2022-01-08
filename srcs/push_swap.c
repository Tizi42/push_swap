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

void	push_swap(int *stack, int size)
{
	if (size < 10)
		push_swap_small(stack, size);
	else
		push_swap_medium(stack, size);
}

void	push_swap_small(int *stack, int size)
{
	int	atop;

	atop = 0;
	while (!sorted(stack, size))
	{
		if (ordered(&stack[atop], size - atop))
			top_sml_a(stack, atop, size);
		else if (stack[atop] > stack[atop + 1])
			sa(stack, atop, 1);
		else
		{
			top_sml_a(stack, atop, size);
			pb(&atop, size);
		}
	}
	while (atop > 0)
		pa(&atop);
}

int	way_to_r(int pivot, int *stack, int size)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i <= size / 2)
	{
		if (stack[i] <= pivot)
			n++;
		i++;
	}
	if (n < pivot / 2)
		return (1);
	return (0);
}

void	push_swap_medium(int *stack, int size)
{
	int	pivot;
	int	atop;
	float	a;

	atop = 0;
	a = size * 0.00875 + 2.625;
//	a = 5;
	int gap = size / a;
	pivot = gap;
//	pivot = size / a;
//	int i;
/*	for (i = 0; i < size; i++)
		printf("%i ", stack[i]);
	printf("\n");*/
//	int w = way_to_r(pivot, stack, size);
	while (pivot < size - 10)
	{
		while (atop <= pivot && !sorted(&stack[atop], size - atop))
		{
			if (stack[atop] <= pivot)
			{
				top_pos_b(stack, atop, insert_pos(stack, atop, stack[atop]));
				pb(&atop, size);
			}
			/*else if (w)
			{
				if (stack[atop + 1] <= pivot)
					sa(stack, atop, 1);
				else
					rrotate_to_next_a(stack, atop, pivot, size);
			//}
			//*/else
				rotate_to_next_a(stack, atop, pivot, size);
			/*for (i = 0; i < size; i++)
			{
				if (i == atop)
					printf("(%i) ", stack[i]);
				else
					printf("%i ", stack[i]);
			}
			printf("\n");*/
		}
		//w = 0;
		if (size > 100 && size - pivot <= 100)
			a = 3.5;
		if (atop > pivot)
		{
			pivot = pivot + (size - pivot) / a;
			//pivot += gap;
			if (pivot == (int)(pivot + (size - pivot) / a))
				pivot = size;
		}
		else
			pivot = size;
/*		if (pivot > 85 && pivot <= 75)
			pivot = 74;*/
	}
	top_pos_b(stack, atop, pos_of_biggest(stack, atop));
	modify_stack(&stack[atop], size - atop);
	push_swap_small(&stack[atop], size - atop);
	while (atop > 0)
		pa(&atop);
}
