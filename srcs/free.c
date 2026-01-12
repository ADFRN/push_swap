/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:43:28 by afournie          #+#    #+#             */
/*   Updated: 2026/01/12 16:52:00 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_stack(t_stack *stack)
{
	t_stack *current;
	t_stack *next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
