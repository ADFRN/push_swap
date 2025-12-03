/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:22:11 by afournie          #+#    #+#             */
/*   Updated: 2025/12/03 18:54:28 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

// void	radix_sort(t_stack *a, t_stack *b)
// {
// 	int	max_bits;
// 	int	size;
// 	int	max_index;
// 	int	index;
// 	int	i;
// 	int	j;
// 	int	index;

// 	max_index = get_max(a);
// 	max_bits = 0;
// 	i = -1;
// 	j = -1;
// 	while ((1 << max_bits) <= max_index)
// 		max_bits++;
// 	while (i++ < max_bits)
// 	{
// 		size = stack_size(a);
// 		while (j++ < size)
// 		{
// 			index = a->index;
// 			if (((index >> i) & 1) == 1)
// 				ra(a);
// 			else
// 				pb(a, b);
// 			if (((index >> i) & 1) == 1)
// 				ra(a);
// 			else
// 				pb(a, b);
// 		}
// 		while (stack_size(b) > 0)
// 			pa(a, b);
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*cur;
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
	cur = stack_a;
	max = get_max(&cur);
	while (cur)
	{
		printf("%d\n", cur->index);
		cur = cur->next;
	}
	return (0);
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
