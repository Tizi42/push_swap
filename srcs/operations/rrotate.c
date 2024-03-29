/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:33:25 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/14 10:33:27 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *stack, int atop, int size, int msg)
{
	rotate(&stack[atop], size - atop, 1);
	if (msg)
		ft_printf("rra\n");
}

void	rrb(int *stack, int atop, int msg)
{
	rotate(stack, atop, -1);
	if (msg)
		ft_printf("rrb\n");
}

void	rrr(int *stack, int atop, int size)
{
	rra(stack, atop, size, 0);
	rrb(stack, atop, 0);
	ft_printf("rrr\n");
}

void	rrr_n(int *stack, int atop, int size, int n)
{
	while (n > 0)
	{
		rrr(stack, atop, size);
		n--;
	}
}
