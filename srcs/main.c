/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:34:39 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/14 10:34:59 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(int *stack, int size)
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

int	ordered(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] - stack[i + 1] != -1 && stack[i] - stack[i + 1] != size - 1)
			return (0);
		i++;
	}
	return (1);
}

void top_sml_a(int *stack, int atop, int size)
{
	int pos;

	pos = 0;
	while (pos < size && stack[pos] != atop)
		pos++;
	if (pos <= size / 2)
		while (stack[atop] != atop)
			ra(stack, atop, size, 1);
	else
		while (stack[atop] != atop)
			rra(stack, atop, size, 1);
}

void	push_swap_small(int *stack, int size)
{
	int atop;

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

int	find_insert_pos(int *stack, int atop, int n)
{
	int pos;

	pos = atop - 1;
	while (pos >= 0)
	{
		if (n > stack[pos])
			return (pos);
		pos--;
	}
	return (pos);
}

void	rb_n(int *stack, int atop, int msg, int n)
{
	while (n > 0)
	{
		rb(stack, atop, msg);
		n--;
	}
}

void	rrb_n(int *stack, int atop, int msg, int n)
{
	while (n > 0)
	{
		rrb(stack, atop, msg);
		n--;
	}
}

void	push_swap_medium(int *stack, int size)
{
	int	pivot;
	int	atop;
	int pos;
	//int i;

	atop = 0;
	pivot = size / 2;
	while (pivot < size - 25)
	{
		while (atop <= pivot && !sorted(&stack[atop], size - atop))
		{
			if (stack[atop] <= pivot)
			{
				pos = find_insert_pos(stack, atop, stack[atop]);
				if (pos >= atop / 2)
				{
					rb_n(stack, atop, 1, atop - pos - 1);
					pb(&atop, size);
					rrb_n(stack, atop, 1, atop - pos - 2);
				}
				else if (pos < atop / 2)
				{
					rrb_n(stack, atop, 1, pos + 1);
					pb(&atop, size);
					rb_n(stack, atop, 1, pos + 2);
				}
			}
			else
				ra(stack, atop, size, 1);
		}
		if (atop > pivot)
			pivot = pivot + (size - pivot) / 2;
		else
			pivot = size;
	}
	modify_stack(&stack[atop], size - atop);
	push_swap_small(&stack[atop], size - atop);
	while (atop > 0)
		pa(&atop);
	//if (!sorted(stack, size))
	//	printf("(error: not sorted)\n");
}

void	push_swap(int *stack, int size)
{
	if (size < 50)
		push_swap_small(stack, size);
	else if (size >= 50)
		push_swap_medium(stack, size);
}

int	main(int ac, char **av)
{
	int *stack;
	int size;

	if (ac == 1)
		return 0;
	stack = NULL;
	size = parse(ac, av, &stack);
	modify_stack(stack, size);
	push_swap(stack, size);
}
