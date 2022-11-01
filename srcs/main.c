/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:34:39 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/15 11:00:01 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit(-1);
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

void	push_swap(int *stack, int size)
{
	if (size < 10)
		push_swap_small(stack, size);
	else
		push_swap_medium(stack, size);
}

int	main(int ac, char **av)
{
	int	*stack;
	int	size;

	if (ac == 1)
		return (1);
	stack = NULL;
	size = parse(ac, av, &stack);
	modify_stack(stack, size);
	push_swap(stack, size);
	free(stack);
	return (0);
}
