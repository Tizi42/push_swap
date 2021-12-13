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

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(int *stack, int atop, int msg)
{
	swap(&stack[atop], &stack[atop + 1]);
	if (msg)
		ft_prntf("sa\n");
}

void	sb(int *stack, int atop, int msg)
{
	if (atop < 2)
	{
		ft_printf("Error: not enough element in b to swap\n");
		return ;
	}
	swap(&stack[atop - 1], &stack[atop - 2]);
	if (msg)
		ft_prntf("sb\n");
}

void	ss(int *stack, int atop)
{
	sa(stack, atop, 0);
	sb(stack, atop, 0);
	ft_prntf("ss\n");
}

void	pb(int *atop, int size)
{
	if (atop >= size - 1)
	{
		ft_printf("Error: no element in stack a for push")
		return ;
	}
	*atop += 1;
	ft_prntf("pb\n");
}

void	pa(int *atop)
{
	if (atop <= 0)
	{
		ft_printf("Error: no element in stack b for push")
		return ;
	}
	*atop -= 1;
	ft_prntf("pa\n");
}

void	rotate(int *n, int size, int direction)
{
	int tmp;
	int i;

	if (direction == 1)
	{
		tmp = n[size - 1];
		while (size > 1)
		{
			n[size - 1] = n[size - 2];
			size--;
		}
		n[0] = tmp;
	}
	else if (direction == -1)
	{
		tmp = n[0];
		i = 0;
		while (i < size - 1)
		{
			n[i] = n[i + 1];
			i++;
		}
		n[size - 1] = tmp;
	}
}

void	ra(int *stack, int atop, int size, int msg)
{
	rotate(&stack[atop], size - atop, -1);
	if (msg)
		ft_printf("ra\n");
}

void	rb(int *stack, int atop, int msg)
{
	rotate(stack, atop, 1);
	if (msg)
		ft_printf("rb\n");
}

void	rr(int *stack, int atop, int msg)
{
	ra(stack, atop, 0);
	rb(stack, atop, 0);
	ft_printf("rr\n");
}

void	rra(int *stack, int atop, int size, int msg)
{
	rotate(&stack[atop], size - atop, 1);
	if (msg)
		ft_printf("rra\n");
}

void	rrb(int *stack, int atop, int msg)
{
	rotate(stack, atop, -1);
	if (msg)
		ft_printf("rrb\n");
}

void	rrr(int *stack, int atop, int msg)
{
	rra(stack, atop, 0);
	rrb(stack, atop, 0);
	ft_printf("rrr\n");
}

int	main(int ac, char **av)
{
	int atop;
	int *stack = {3, 9, 7};
	int size = 3;

	//if (ac < 2)
	//	return (0);
	//a = parse(av + 1, ac - 1);
	atop = 0;
	if (size == 1)
		return ;
	while (!sorted(stack))
	{
		if (stack[atop] > stack[atop + 1])
			sa(stack, atop, 1);
		
	}

}
