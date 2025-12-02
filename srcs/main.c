/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:22:11 by afournie          #+#    #+#             */
/*   Updated: 2025/12/02 19:20:04 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

int		create_list(t_stack **lst, int value);
t_stack	*ft_stacknew(int value);

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
	cur = stack_a;
	max = get_max(stack_a);
	while (cur)
	{
		printf("%d\n", cur->value);
		cur = cur->next;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		nbr;
	int		sign;
	size_t	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * sign);
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
		if (tmp->next)
			tmp->next->prev = tmp;
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
	node->prev = NULL;
	return (node);
}
