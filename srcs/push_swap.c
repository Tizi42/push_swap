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
	if (size < 50)
		push_swap_small(stack, size);
	else if (size >= 50)
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

void	push_swap_medium(int *stack, int size)
{
	int	pivot;
	int	atop;
//	float	a;

	atop = 0;
//	a = (size - atop) * 0.01125 + 2.375;
	pivot = size / 3.5;
/*	int i;
	for (i = 0; i < size; i++)
		printf("%i ", stack[i]);
	printf("\n");*/
	while (pivot < size - 25)
	{
		while (atop <= pivot && !sorted(&stack[atop], size - atop))
		{
			if (stack[atop] <= pivot)
			{
				top_pos_b(stack, atop, insert_pos(stack, atop, stack[atop]));
				pb(&atop, size);
			}
			else
				rotate_to_next_a(stack, atop, pivot, size);
/*			for (i = 0; i < size; i++)
			{
				if (i == atop)
					printf("(%i) ", stack[i]);
				else
					printf("%i ", stack[i]);
			}
			//printf("\n"); */
		}
//		if (size - atop >= 100)
//			a = (size - atop) * 0.01125 + 2.375;
		if (atop > pivot)
			pivot = pivot + (size - pivot) / 3.5;
		else
			pivot = size;
	}
	top_pos_b(stack, atop, pos_of_biggest(stack, atop));
	modify_stack(&stack[atop], size - atop);
	push_swap_small(&stack[atop], size - atop);
	while (atop > 0)
		pa(&atop);
}
