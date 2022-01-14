/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:33:29 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/14 10:33:31 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(int *stack, int atop, int msg)
{
	swap(&stack[atop], &stack[atop + 1]);
	if (msg)
		ft_printf("sa\n");
}

void	sb(int *stack, int atop, int msg)
{
	if (atop < 2)
		return ;
	swap(&stack[atop - 1], &stack[atop - 2]);
	if (msg)
		ft_printf("sb\n");
}

void	ss(int *stack, int atop)
{
	sa(stack, atop, 0);
	sb(stack, atop, 0);
	ft_printf("ss\n");
}
