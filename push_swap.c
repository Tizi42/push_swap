#include "push_swap.h"

void	syntax_check(char **arg, int n)
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
	
}

int	main(int ac, char **av)
{
	int *a;

	if (ac < 2)
		return (0);
	a = parse(av + 1, ac - 1);

}
