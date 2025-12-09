/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:32:32 by afournie          #+#    #+#             */
/*   Updated: 2025/12/08 10:54:38 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_within_int_limits(const char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	if (str[0] == '-' || str[0] == '+')
		i = 1;
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (!overflow_check(num, sign))
			return (0);
		i++;
	}
	return (1);
}

int	validate_arg(int *values, int count, const char *arg)
{
	if (!is_valid_integer(arg))
		return (0);
	if (!is_within_int_limits(arg))
		return (0);
	values[count] = ft_atoi(arg);
	if (check_duplicate(values, count, values[count]))
		return (0);
	return (1);
}

int	check_errors(int argc, char **argv)
{
	int	i;
	int	*values;
	int	count;

	if (argc <= 1)
		return (0);
	values = malloc(sizeof(int) * (argc - 1));
	if (!values)
		return (write(2, "Error\n", 6), 1);
	count = 0;
	i = 1;
	while (i < argc)
	{
		if (!validate_arg(values, count, argv[i++]))
		{
			free(values);
			write(2, "Error\n", 6);
			return (1);
		}
		count++;
	}
	free(values);
	return (0);
}
