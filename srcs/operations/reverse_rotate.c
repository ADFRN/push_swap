/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:54:10 by afournie          #+#    #+#             */
/*   Updated: 2026/01/12 12:29:08 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = first;
	*stack_a = last;
	write(1, "rra\n", 4);
}
