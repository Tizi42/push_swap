# include "push_swap.h"

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

int	sizeof_tab(char **tab)
{
	int n;

	n = 0;
	while (tab && tab[n])
		n++;
	return (n);
}
