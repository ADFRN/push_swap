/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:32:32 by afournie          #+#    #+#             */
/*   Updated: 2025/12/02 18:37:58 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_errors(int argc, char *argv)
{
	if (!argc)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
