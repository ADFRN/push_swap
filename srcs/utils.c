/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:13 by afournie          #+#    #+#             */
/*   Updated: 2025/12/02 19:16:58 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max(t_stack **stack_a)
{
	int		max;
	t_stack	*tmp;

	tmp = stack_a;
	max = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
		}
		tmp = tmp->next;
	}
	return (max);
}
