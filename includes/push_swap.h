/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:21:58 by afournie          #+#    #+#             */
/*   Updated: 2026/01/12 12:33:43 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_stacknew(int value);
int					get_max(t_stack **stack_a);
void				sort_two(t_stack **stack_a);
int					min_value(t_stack **stack_a);
void				assign_index(t_stack **stack);
void				sort_three(t_stack **stack_a);
int					already_sorted(t_stack **stack_a);
char				*join_args(int argc, char **argv);
int					is_valid_integer(const char *str);
int					overflow_check(long num, int sign);
int					check_errors(int argc, char **argv);
int					check_errors(int argc, char **argv);
int					create_list(t_stack **lst, int value);
int					is_within_int_limits(const char *str);
int					parse_string_args(char *arg, t_stack **stack_a);
int					find_position(t_stack **stack, int target_index);
int					validate_arg(int *values, int count, const char *arg);
int					check_duplicate(int *values, int count, int new_value);
int					check_duplicate(int *values, int count, int new_value);
void				sort_five(t_stack **stack_a, t_stack **stack_b, int max);
void				sort_small(t_stack **stack_a, t_stack **stack_b, int max);
void				radix_sort(t_stack **stack_a, t_stack **stack_b, int max);
void				sort_stacks(t_stack **stack_a, t_stack **stack_b, int max);

void				sa(t_stack **stack_a);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rra(t_stack **stack_a);

#endif
