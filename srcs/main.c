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

void	clean_exit(int *stack)
{
	free(stack);
	write(2, "Error\n", 6);
	exit(-1);
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
