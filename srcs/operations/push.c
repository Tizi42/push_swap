/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:32:48 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/14 10:32:54 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(int *atop, int size)
{
	if (*atop >= size - 1)
		return ;
	*atop += 1;
	ft_printf("pb\n");
}

void	pa(int *atop)
{
	if (*atop <= 0)
		return ;
	*atop -= 1;
	ft_printf("pa\n");
}
