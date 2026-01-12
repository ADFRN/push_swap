/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:34:07 by afournie          #+#    #+#             */
/*   Updated: 2026/01/12 12:33:26 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	find_position(t_stack **stack, int target_index)
{
	t_stack	*current;
	int		pos;

	current = *stack;
	pos = 0;
	while (current)
	{
		if (current->index == target_index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int max)
{
	if (max == 1)
		return ;
	if (max == 2)
		sort_two(stack_a);
	else if (max == 3)
		sort_three(stack_a);
	else if (max <= 5)
		sort_five(stack_a, stack_b, max);
}

void	sort_two(t_stack **stack_a)
{
	int	a;
	int	b;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	if (a > b)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	i;
	int	pos;

	i = 0;
	while (i < (max - 3))
	{
		while ((*stack_a)->index != i)
		{
			pos = find_position(stack_a, i);
			if (pos <= (max - i) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
