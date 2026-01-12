/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:22:11 by afournie          #+#    #+#             */
/*   Updated: 2026/01/12 16:57:12 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*args_str;
	int		max;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		args_str = ft_strdup(argv[1]);
	else
		args_str = join_args(argc, argv);
	if (!args_str)
		return (write(2, "Error\n", 6), 1);
	if (parse_string_args(args_str, &stack_a))
		return (free_stack(stack_a), free_stack(stack_b), free(args_str), 1);
	free(args_str);
	assign_index(&stack_a);
	max = get_max(&stack_a);
	if (already_sorted(&stack_a))
		return (free_stack(stack_a), free_stack(stack_b), EXIT_SUCCESS);
	sort_stacks(&stack_a, &stack_b, max);
	return (free_stack(stack_a), free_stack(stack_b), EXIT_SUCCESS);
}

int	already_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_a);
	while (tmp->next)
	{
		if (tmp->index < tmp->next->index)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b, int max)
{
	if (max < 5)
		sort_small(stack_a, stack_b, max + 1);
	else
		radix_sort(stack_a, stack_b, max);
}

void	assign_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = *stack;
	while (current)
	{
		index = 0;
		compare = *stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < (max + 1))
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while ((*stack_b) != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}
