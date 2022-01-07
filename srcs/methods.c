/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:06:58 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 11:06:59 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_sml_a(int *stack, int atop, int size)
{
	int	pos;

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

void	top_pos_b(int *stack, int atop, int pos)
{
	if (atop < 2 || pos >= atop)
		return ;
	if (pos >= atop / 2)
		rb_n(stack, atop, 1, atop - pos - 1);
	else if (pos < atop / 2)
		rrb_n(stack, atop, 1, pos + 1);
}

int	insert_pos(int *stack, int atop, int n)
{
	int	pbig;
	int	psml;

	pbig = pos_of_biggest(stack, atop);
	psml = pos_of_smallest(stack, atop);
	while (pbig != psml)
	{
		if (n > stack[pbig])
			return (pbig);
		if (--pbig < 0)
			pbig = atop - 1;
	}
	if (pbig >= 0 && pbig == psml)
	{
		if (n > stack[psml])
			return (psml);
		else
			return (psml - 1);
	}
	return (-1);
}

void	rotate_to_next_a(int *stack, int atop, int pivot, int size)
{
	int	com;
	int	ra;

	com = common_rt_times(stack, atop, pivot, &ra);
	rr_n(stack, atop, size, com);
	ra_n(stack, atop, size, ra - com);
}
