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
		rb_n(stack, atop, atop - pos - 1);
	else if (pos < atop / 2)
		rrb_n(stack, atop, pos + 1);
}

int	insert_pos_a(int *stack, int atop, int size, int n)
{
	int	pbig;
	int	psml;

	pbig = atop + pos_of_biggest(&stack[atop], size - atop);
	psml = atop + pos_of_smallest(&stack[atop], size - atop);
	while (psml != pbig)
	{
		if (n < stack[psml])
			return (psml);
		if (++psml > size - 1)
			psml = atop;
	}
	if (n < stack[pbig])
		return (pbig);
	else
		return (pbig + 1);
}

void	top_pos_a(int *stack, int atop, int size, int pos)
{
	if (pos <= atop || pos >= size)
		return ;
	if (pos <= atop + (size - atop) / 2)
		ra_n(stack, atop, size, pos - atop);
	else if (pos > atop + (size - atop) / 2)
		rra_n(stack, atop, size, size - pos);
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
