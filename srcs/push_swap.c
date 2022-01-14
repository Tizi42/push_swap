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

void	print_list(int *stack, int atop, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (i == atop)
			printf("(%i) ", stack[i]);
		else
			printf("%i ", stack[i]);
	}
	printf("\n");
}


void	push_swap_small(int *stack, int size)
{
	int	atop;

	atop = 0;
	while (!continuous_sorted(stack, size))
	{
		if (continuous_ordered(&stack[atop], size - atop))
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
	int		rvs;
	int		atop;

//	print_list(stack, 0, size);
	rvs = reverse(stack, 0, size, 0);
	atop = partition_insertion(stack, size, next_pivot(0, size, 0), rvs);
	top_pos_b(stack, atop, pos_of_biggest(stack, atop));
//	printf("atop %i srack[atop] %i\n", atop, stack[atop]);
	if (status(&stack[atop], size - atop) >= ORDERED)
	{
//		printf("case or\n");
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

/*void	adjust(int *stack, int atop, int size)
{

}*/

int	partition_insertion(int *stack, int size, int pivot, int rvs)
{
	int		atop;

	atop = 0;
	while (pivot < size - 10)
	{
		while (atop <= pivot && status(&stack[atop], size - atop) < ORDERED)
		{
			/*if (stack[atop] <= pivot && (stack[atop + 1] <= pivot || stack[size - 1] <= pivot)
				sa(stack, atop, 1);
			if (!rvs && stack[size - 1] <= pivot)
				rra(stack, atop, size, 1);
			else*/ if (stack[atop] <= pivot)
			{
				top_pos_b(stack, atop, insert_pos(stack, atop, stack[atop]));
				pb(&atop, size);
			}
			else if (rvs)
				rrotate_to_next_a(stack, atop, pivot, size);
			else
				rotate_to_next_a(stack, atop, pivot, size);
		}
		rvs = reverse(stack, atop, size, pivot);
		pivot = next_pivot(atop, size, pivot);
	}
	return (atop);
}
