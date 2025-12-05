/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:22:11 by afournie          #+#    #+#             */
/*   Updated: 2025/12/05 05:18:30 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		max;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	if (argc <= 1)
		return (0);
	while (i++ < (argc - 1))
		create_list(&stack_a, ft_atoi(argv[i]));
	assign_index(&stack_a);
	max = get_max(&stack_a);
	radix_sort(&stack_a, &stack_b, max);
	return (0);
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
