/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:13 by afournie          #+#    #+#             */
/*   Updated: 2025/12/03 18:46:32 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_stack **stack_a)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack_a;
	max = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
		}
		tmp = tmp->next;
	}
	return (max);
}
