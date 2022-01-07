/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:07:48 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 11:07:49 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rr_n(int *stack, int atop, int size, int n)
{
	while (n > 0)
	{
		rr(stack, atop, size);
		n--;
	}
}

void	ra_n(int *stack, int atop, int size, int n)
{
	while (n > 0)
	{
		ra(stack, atop, size, 1);
		n--;
	}
}
