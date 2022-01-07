/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:31:19 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/16 11:31:21 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int ac, char **av, int **stack)
{
	int		i;
	char	**tab;
	int		size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		tab = ft_split(av[i], ' ');
		if (!valid_elements(tab))
		{
			free_split(tab);
			clean_exit(*stack);
		}
		size = append_stack(stack, tab, size);
		free_split(tab);
		i++;
	}
	if (dupli_element(*stack, size))
		clean_exit(*stack);
	return (size);
}

void	exchange_sort(int (*lst)[2], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (lst[i][0] > lst[j][0])
			{
				ft_swap(&lst[i][0], &lst[j][0]);
				ft_swap(&lst[i][1], &lst[j][1]);
			}
			j++;
		}
		i++;
	}
}

/*
** This fonction changes the value of each element in the stack,
** so that the new value will be its final position(index) after sorting.
** For example:
** stack = {258, 20, 67} will become stack = {2, 0, 1}
**
** val_pos is a list of int[2]
** val_pos[i][0] = the original value stack[i]
** val_pos[i][1] = the original position(index) i
**
** Steps:
** 1) Set val_pos with the original value and positon of each element.
** 2) Sort val_pos according to elemets' original value.
** 3) Set stack elements's new value to its final position index:
**               stack[val_pos[i][1]] = i;
** i = the final index
** val_pos[i][1] = the original index
*/
void	modify_stack(int *stack, int size)
{
	int	(*val_pos)[2];
	int	i;

	val_pos = malloc(sizeof(int) * 2 * size);
	i = 0;
	while (i < size)
	{
		val_pos[i][0] = stack[i];
		val_pos[i][1] = i;
		i++;
	}
	exchange_sort(val_pos, size);
	i = 0;
	while (i < size)
	{
		stack[val_pos[i][1]] = i;
		i++;
	}
	free(val_pos);
}

int	append_stack(int **stack, char **tab, int old_size)
{
	int		*tmp;
	int		i;
	int		new_size;

	tmp = *stack;
	new_size = old_size + sizeof_tab(tab);
	*stack = ft_malloc(sizeof(int) * new_size);
	i = 0;
	while (i < old_size)
	{
		(*stack)[i] = tmp[i];
		i++;
	}
	if (tmp)
		free(tmp);
	while (i < new_size && *tab)
	{
		(*stack)[i] = ft_atoi(*tab);
		i++;
		tab++;
	}
	return (new_size);
}
