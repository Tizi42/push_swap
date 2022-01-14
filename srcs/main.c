/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:34:39 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 16:00:19 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit(-1);
}

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
		return (0);
	stack = NULL;
	size = parse(ac, av, &stack);
	modify_stack(stack, size);
	push_swap(stack, size);
	free(stack);
}
