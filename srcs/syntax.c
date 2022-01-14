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

unsigned int	ft_atoui(const char *str)
{
	unsigned int	n;

	n = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += (*str - 48);
		str++;
	}
	return (n);
}

int	within_int_limit(char *tab, int size)
{
	unsigned int	n;
	int				signe;

	signe = 0;
	if (tab[0] == '-')
		signe = 1;
	if (size > 10 + signe || (size == 10 + signe && tab[signe] > '2'))
		return (0);
	n = ft_atoui(tab);
	if ((n > 2147483647 && signe == 0) || n > 2147483648)
		return (0);
	return (1);
}

int	valid_elements(char **tab)
{
	int	i;
	int	j;

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
		if (!within_int_limit(tab[i], j) || (j == 1 && tab[i][0] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	dupli_element(int *stack, int size)
{
	int	i;
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
