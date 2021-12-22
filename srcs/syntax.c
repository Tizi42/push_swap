/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:32:47 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/16 11:32:48 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_elements(char **tab)
{
	int	i;
	int	j;

	/*if (tab[0] == "") //?
	{
		printf("empty!");
		return (0);
	}*/
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]))
			{
				if (j != 0 || (j == 0 && tab[i][j] != '-'))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	dupli_element(int *stack, int size)
{
	int i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j-- > 0)
			if (stack[i] == stack[j])
				return (1);
		i++;
	}
	return (0);
}
