#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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
void	rr(int *stack, int atop, int size, int msg);

/*rrotate.c */
void	rra(int *stack, int atop, int size, int msg);
void	rrb(int *stack, int atop, int msg);
void	rrr(int *stack, int atop, int size, int msg);

#endif
