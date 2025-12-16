/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:15:00 by afournie          #+#    #+#             */
/*   Updated: 2025/12/16 17:09:57 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	validate_and_add(char **args, int *values, t_stack **stack_a)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (args[i])
	{
		if (!validate_arg(values, count, args[i]))
			return (0);
		create_list(stack_a, ft_atoi(args[i]));
		count++;
		i++;
	}
	return (1);
}

void	free_exit(int *values, char **args)
{
	int	i;

	i = 0;
	free(values);
	while (args[i])
		free(args[i++]);
	free(args);
	write(2, "Error\n", 6);
}

int	parse_string_args(char *arg, t_stack **stack_a)
{
	char	**args;
	int		i;
	int		*values;

	args = ft_split(arg, ' ');
	if (!args)
		return (write(2, "Error\n", 6), 1);
	i = 0;
	while (args[i])
		i++;
	values = malloc(sizeof(int) * i);
	if (!values)
		return (write(2, "Error\n", 6), 1);
	if (!validate_and_add(args, values, stack_a))
	{
		free_exit(values, args);
		return (1);
	}
	free(values);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	return (0);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		temp = ft_strjoin(joined, " ");
		if (!temp)
			return (free(joined), NULL);
		free(joined);
		joined = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!joined)
			return (NULL);
		i++;
	}
	return (joined);
}
