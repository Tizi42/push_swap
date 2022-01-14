#include	"push_swap.h"

int	reverse_r(int pivot, int pivot_s, int *stack, int size)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i <= size / 2)
	{
		if (stack[i] <= pivot)
			n++;
		i++;
	}
	if (n < pivot_s / 2)
		return (1);
	return (0);
}

void	print_list(int *stack, int atop, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (i == atop)
			printf("(%i) ", stack[i]);
		else
			printf("%i ", stack[i]);
	}
	printf("\n");
}

int	next_pivot(int atop, int size, int pivot)
{
	float	a;

	a = size * 0.00875 + 2.625;
	if (size > 100 && size - pivot <= 100)
		a = 3.5;
	if (atop > pivot)
	{
		pivot += (size - pivot) / a;
		if (pivot == (int)(pivot + (size - pivot) / a))
			pivot = size;
	}
	else
		pivot = size;
	return (pivot);
}

typedef struct stackm
{
	int n;
	int con;
} stackm;

stackm	*contine(int *stack, int size)
{
	int i;
	int head;
	int end;
	stackm *stcm;

	stcm = ft_malloc(10 * size);
	i = 0;
	int old_head = 0;
	int old_end = -1;
	head = 0;
	end = -1;
	while (i < size - 1)
	{
		if (stack[i] < stack[i + 1])
		{
			head = i++;
			while (i < size - 1 && stack[i] < stack[i + 1])
			{
				i++;
			}
			end = i;
		}
		if (end - head > old_end - old_head)
		{
			old_end = end;
			old_head = head;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		stcm[i].n = stack[i];
		if (i >= old_head && i <= old_end)
			stcm[i].con = 1;
		else
			stcm[i].con = 0;
		i++;
	}
	return stcm;
}

int con_of(stackm *s, int size, int n)
{
	int i = 0;

	while (i < size)
	{
		if (s[i].n == n)
			return s[i].con;
		i++;
	}
	return (0);
}

int	try(int *stack, int size, int pivot, int rvs)
{
	int	atop;

	atop = 0;
	int i;
	i = 0;
	stackm *stcm;
	stcm = contine(stack, size);
	pivot = size / 4;
	rvs = 0;
	while (pivot <= size - 0)
	{
		i = 0;
		while (i <= size / 4 + 1 && status(&stack[atop], size - atop) < ORDERED)
		{
			/*if (stack[atop] - stack[atop + 1] == 1)
				sa(stack, atop, 1);*/
			if (con_of(stcm, size, stack[atop]))
			{
				if (stack[atop] <= pivot)
				{
					i++;
				}
				ra(stack, atop, size, 1);
			}
			else if (stack[atop] <= pivot)
			{
				top_pos_b(stack, atop, insert_pos(stack, atop, stack[atop]));
				pb(&atop, size);
				i++;
			}
			else
				ra(stack, atop, size, 1);
		}
/*		float a;
		a = size * 0.00875 + 2.625;
		if (size > 100 && size - pivot <= 100)
			a = 3.5;
		int s = (size - pivot) / a;
		pivot = next_pivot(atop, size, pivot);*/
		pivot += size / 4;
		//rvs = reverse_r(pivot, s, &stack[atop], size - atop);
	}
	return (atop);
}

int	partition_insertion(int *stack, int size, int pivot, int rvs)
{
	int	atop;

	atop = 0;
	//rvs = 0;
	//print_list(stack, atop, size);
	while (pivot < size - 0)
	{
		//printf("rvs: %i\n", rvs);
		while (atop <= pivot && status(&stack[atop], size - atop) < ORDERED)
		{
			if (stack[atop] - stack[atop + 1] == 1)
				sa(stack, atop, 1);
			else if (stack[atop] <= pivot)
			{
				top_pos_b(stack, atop, insert_pos(stack, atop, stack[atop]));
				pb(&atop, size);
			}
			else if (rvs)
			{
				//if (stack[atop + 1] <= pivot)
				//	sa(stack, atop, 1);
				//else
					rrotate_to_next_a(stack, atop, pivot, size);
			}
			else
				rotate_to_next_a(stack, atop, pivot, size);
		}
//		print_list(stack, atop, size);
//		printf("pivot:%i\n", pivot);
		float a;
		a = size * 0.00875 + 2.625;
		if (size > 100 && size - pivot <= 100)
			a = 3.5;
		int s = (size - pivot) / a;
		pivot = next_pivot(atop, size, pivot);
		rvs = reverse_r(pivot, s, &stack[atop], size - atop);
	}
	return (atop);
}

int	insert_pos_a(int *stack, int atop, int size, int n)
{
	int	pbig;
	int	psml;

	pbig = atop + pos_of_biggest(&stack[atop], size - atop);
	psml = atop + pos_of_smallest(&stack[atop], size - atop);
	while (psml != pbig)
	{
		if (n < stack[psml])
			return (psml);
		if (++psml > size - 1)
			psml = atop;
	}
	if (n < stack[pbig])
		return (pbig);
	else
	 	return (pbig + 1);
}

void	top_pos_a(int *stack, int atop, int size, int pos)
{
	if (pos <= atop || pos >= size)
		return ;
	if (pos <= atop + (size - atop) / 2)
		ra_n(stack, atop, size, pos - atop);
	else if (pos > atop + (size - atop) / 2)
		rra_n(stack, atop, size, size - pos);
}

void	push_swap_medium(int *stack, int size)
{
	float	a;
	int		rvs;
	int		atop;

	a = size * 0.00875 + 2.625;
	rvs = reverse_r(size / a, size / a, stack, size);
//	atop = partition_insertion(stack, size, size / a, rvs);
	atop = try(stack, size, size / a, rvs);
	top_pos_b(stack, atop, pos_of_biggest(stack, atop));
//	printf("after top pos b:\n");
//	print_list(stack, atop, size);
	if (status(&stack[atop], size - atop) >= ORDERED)
	{
//		printf("case ordered:\n");
		while (atop > 0)
		{
//			printf("insert pos a:%i\n", insert_pos_a(stack, atop, size, stack[atop - 1]));
			top_pos_a(stack, atop, size, insert_pos_a(stack, atop, size, stack[atop - 1]));
			pa(&atop);
		}
		top_sml_a(stack, atop, size);
	}
	else
	{
		modify_stack(&stack[atop], size - atop);
		push_swap_small(&stack[atop], size - atop);
		while (atop > 0)
			pa(&atop);
	}
//	print_list(stack, atop, size);
}

int	top_b_time_after_com(int type, int *stack, int atop, int size, int com, int val)
{
	int n;
	int *cp;
	int pos;

	cp = ft_malloc(sizeof(int) * size);
	n = 0;
	while (n < size)
	{
		cp[n] = stack[n];
		n++;
	}
	if (type == 1)
	{
		while (com > 0)
		{
			rb(cp, atop, 0);
			com--;
		}
	}
	else if (type == 2)
	{
		while (com > 0)
		{
			rrb(cp, atop, 0);
			com--;
		}
	}
	pos = insert_pos(cp, atop, val);
	if (atop < 2 || pos >= atop)
		return (0);
	if (pos >= atop / 2)
		n = atop - pos - 1;
	else
		n = pos + 1;
	free(cp);
	return (n);
}
