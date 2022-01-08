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

int	pos_of_next_a_r(int *stack, int pivot, int size)
{
	size--;
	while (stack[size] > pivot)
		size--;
	return (size);
}

int	common_rrt_times(int *stack, int atop, int pivot, int *rra, int size)
{
	int	ret;
	int	rrb;
	int	apos;
	int	bpos;

	apos = pos_of_next_a_r(stack, pivot, size);
	*rra = size - apos;
	bpos = insert_pos(stack, atop, stack[apos]);
	rrb = bpos + 1;
	ret = ft_min(*rra, rrb);
	if (bpos >= atop / 2 && rrb - ret > atop - bpos - 1)
		ret = 0;
	return (ret);
}

void	rra_n(int *stack, int atop, int size, int n)
{
	while (n > 0)
	{
		rra(stack, atop, size, 1);
		n--;
	}
}

void	rrr_n(int *stack, int atop, int size, int n)
{
	while (n > 0)
	{
		rrr(stack, atop, size);
		n--;
	}
}

int	top_b_time_after_com(int type, int *stack, int atop, int size, int com, int val)
{
	int n;
	int *cp;
	int pos;

	cp = ft_malloc(sizeof(int) * size);
	n = 0;
	while (n < size)
	{
		cp[n] = stack[n];
		n++;
	}
	if (type == 1)
	{
		while (com > 0)
		{
			rb(cp, atop, 0);
			com--;
		}
	}
	else if (type == 2)
	{
		while (com > 0)
		{
			rrb(cp, atop, 0);
			com--;
		}
	}
	pos = insert_pos(cp, atop, val);
	if (atop < 2 || pos >= atop)
		return (0);
	if (pos >= atop / 2)
		n = atop - pos - 1;
	else
		n = pos + 1;
	free(cp);
	return (n);
}

void	rrotate_to_next_a(int *stack, int atop, int pivot, int size)
{
//	int	com;
//	int	n_a;
	int n1;
	int a1;
	int	n2;
	int a2;

	int p1 = pos_of_next_a(stack, atop, pivot);
//	printf("apos r: %i\n", apos_r);
	int p2 = pos_of_next_a_r(stack, pivot, size);
//	printf("apos rr: %i\n", apos_rr);*/
	n1 = common_rt_times(stack, atop, pivot, &a1);
	n2 = common_rrt_times(stack, atop, pivot, &a2, size);
	n1 = n1 > 0? n1 : 0;
	n2 = n2 > 0? n2 : 0;
	if (a1 < 0)
		a1 = 0;
	if (a2 < 0)
		a2 = 0;
	int b1 = top_b_time_after_com(1, stack, atop, size, n1, stack[p1]);
	int b2 = top_b_time_after_com(2, stack, atop, size, n2, stack[p2]);

	if (a1 + b1 <= a2 + b2)
	{
		//com = common_rt_times(stack, atop, pivot, &n_a);
		rr_n(stack, atop, size, n1);
		ra_n(stack, atop, size, a1 - n1);
	}
	else
	{
		//com = common_rrt_times(stack, atop, pivot, &n_a, size);
		rrr_n(stack, atop, size, n2);
		rra_n(stack, atop, size, a2 - n2);
	}
}
