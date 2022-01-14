/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:32:56 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/14 10:32:58 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *n, int size, int direction)
{
	int	tmp;
	int	i;

	if (direction == 1)
	{
		tmp = n[size - 1];
		while (size > 1)
		{
			n[size - 1] = n[size - 2];
			size--;
		}
		n[0] = tmp;
	}
	else if (direction == -1)
	{
		tmp = n[0];
		i = 0;
		while (i < size - 1)
		{
			n[i] = n[i + 1];
			i++;
		}
		n[size - 1] = tmp;
	}
}

void	ra(int *stack, int atop, int size, int msg)
{
	rotate(&stack[atop], size - atop, -1);
	if (msg)
		ft_printf("ra\n");
}

void	rb(int *stack, int atop, int msg)
{
	rotate(stack, atop, 1);
	if (msg)
		ft_printf("rb\n");
}

void	rr(int *stack, int atop, int size)
{
	ra(stack, atop, size, 0);
	rb(stack, atop, 0);
	ft_printf("rr\n");
}
