/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:11:13 by afournie          #+#    #+#             */
/*   Updated: 2025/12/08 10:40:50 by afournie         ###   ########.fr       */
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

int	create_list(t_stack **lst, int value)
{
	t_stack	*tmp;

	if (!lst)
		return (0);
	if (*lst == NULL)
		*lst = ft_stacknew(value);
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_stacknew(value);
	}
	return (1);
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

int	overflow_check(long num, int sign)
{
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > (long)INT_MAX + 1))
		return (0);
	return (1);
}

int	check_duplicate(int *values, int count, int new_value)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (values[i] == new_value)
			return (1);
		i++;
	}
	return (0);
}
