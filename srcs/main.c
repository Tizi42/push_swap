/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:34:39 by tyuan             #+#    #+#             */
/*   Updated: 2021/12/14 10:34:59 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	syntax_check(char **arg, int n)
{
	int	i;
	int	j;

	i = 0;
	while(i < n)
	{
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]) && arg[i][j] != ' ')
				error_exit("Error\n");
			j++;
		}
		i++；
	}
}

int	*parse(char **arg, int n)
{
	syntax_check(arg, n);

}*/

int	sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] != i)
			return (0);
		i++;
	}
	return (1);
}

int	ordered(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] - stack[i + 1] != -1 && stack[i] - stack[i + 1] != size - 1)
			return (0);
		i++;
	}
	return (1);
}

void top_sml_a(int *stack, int atop, int size)
{
	int pos;

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

void push_swap(int *stack, int size)
{
	int atop;

	atop = 0;
	while (!sorted(stack, size))
	{
		if (ordered(&stack[atop], size - atop))
			top_sml_a(stack, atop, size);
		else if (stack[atop] > stack[atop + 1])
			sa(stack, atop, 1);
		else
		{
			top_sml_a(stack, atop, size);
			pb(&atop, size);
		}
	}
	while (atop > 0)
		pa(&atop);
}

int	sizeof_tab(char **tab)
{
	int n;

	n = 0;
	while (tab && tab[n])
		n++;
	return (n);
}

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

void free_split(char **tab)
{
	int i;

	if (tab)
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
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

int	main(int ac, char **av)
{
	int *stack;
	int size;

	if (ac == 1)
		return 0;
	stack = NULL;
	size = parse(ac, av, &stack);
	modify_stack(stack, size);
	push_swap(stack, size);
}
