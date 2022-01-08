/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:44:16 by tyuan             #+#    #+#             */
/*   Updated: 2022/01/07 15:44:17 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft.h"

void	rrotate_to_next_a(int *stack, int atop, int pivot, int size);


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

/* multi_ops.c */
void	rb_n(int *stack, int atop, int n);
void	rrb_n(int *stack, int atop, int n);
void	rr_n(int *stack, int atop, int size, int n);
void	ra_n(int *stack, int atop, int size, int n);

/* parse.c */
void	modify_stack(int *stack, int size);
int		parse(int ac, char **av, int **stack);
int		append_stack(int **stack, char **tab, int old_size);

/* syntax.c */
int		dupli_element(int *stack, int size);
int		valid_elements(char **tab);

/* lib.c */
void	free_split(char **tab);
int		sizeof_tab(char **tab);
int		ft_min(int a, int b);

/* push_swap.c */
void	push_swap(int *stack, int size);
void	push_swap_small(int *stack, int size);
void	push_swap_medium(int *stack, int size);

/* methods.c */
void	top_sml_a(int *stack, int atop, int size);
void	top_pos_b(int *stack, int atop, int pos);
int		insert_pos(int *stack, int atop, int n);
void	rotate_to_next_a(int *stack, int atop, int pivot, int size);

/* order_check.c */
int		ordered(int *stack, int size);
int		sorted(int *stack, int size);

/* calculate.c */
int		pos_of_smallest(int *stack, int size);
int		pos_of_biggest(int *stack, int size);
int		pos_of_next_a(int *stack, int atop, int pivot);
int		common_rt_times(int *stack, int atop, int pivot, int *ra);

/* main.c */
void	clean_exit(int *stack);

#endif
