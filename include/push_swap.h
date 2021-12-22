#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

/* push.c */
void	pb(int *atop, int size);
void	pa(int *atop);

/* swap.c */
void	swap(int *a, int *b);
void	sa(int *stack, int atop, int msg);
void	sb(int *stack, int atop, int msg);
void	ss(int *stack, int atop);

/* rotate.c */
void	rotate(int *n, int size, int direction);
void	ra(int *stack, int atop, int size, int msg);
void	rb(int *stack, int atop, int msg);
void	rr(int *stack, int atop, int size);

/*rrotate.c */
void	rra(int *stack, int atop, int size, int msg);
void	rrb(int *stack, int atop, int msg);
void	rrr(int *stack, int atop, int size);

void	modify_stack(int *stack, int size);
int		parse(int ac, char **av, int **stack);
int		append_stack(int **stack, char **tab, int old_size);

int		dupli_element(int *stack, int size);
int		valid_elements(char **tab);

void	free_split(char **tab);
int		sizeof_tab(char **tab);

void	push_swap(int *stack, int size);
void	push_swap_small(int *stack, int size);
void	top_sml_a(int *stack, int atop, int size);
int		ordered(int *stack, int size);
int		sorted(int *stack, int size);

#endif
