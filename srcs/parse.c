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
		if(!valid_elements(tab))
		{
			free_split(tab);
			if (*stack)
				free(*stack);
			exit(-1); //clean_exit();
		}
		size = append_stack(stack, tab, size);
		free_split(tab);
		i++;
	}
	if(dupli_element(*stack, size))
	{
		free(*stack);
		exit(-1);
	}
	return (size);
}

void	modify_stack(int *stack, int size)
{
	int	(*val_pos)[2];
	int	i;
	int j;
	int	tmp[2];

	val_pos = malloc(sizeof(int) * 2 * size);
	i = 0;
	while (i < size)
	{
		val_pos[i][0] = stack[i];
		val_pos[i][1] = i;
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (val_pos[i][0] > val_pos[j][0])
			{
				tmp[0] = val_pos[i][0];
				tmp[1] = val_pos[i][1];
				val_pos[i][0] = val_pos[j][0];
				val_pos[i][1] = val_pos[j][1];
				val_pos[j][0] = tmp[0];
				val_pos[j][1] = tmp[1];
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		stack[val_pos[i][1]] = i;
		i++;
	}
}

int	append_stack(int **stack, char **tab, int old_size)
{
	int		*tmp;
	int 	i;
	int		new_size;

	tmp = *stack;
	new_size = old_size + sizeof_tab(tab);
	*stack = malloc(sizeof(int) * new_size);
	i = 0;
	while (i < old_size)
	{
		(*stack)[i] = tmp[i];
		i++;
	}
	if (tmp)
		free(tmp); //v_free(tmp);
	while (i < new_size && *tab)
	{
		(*stack)[i] = ft_atoi(*tab);
		i++;
		tab++;
	}
	return (new_size);
}
