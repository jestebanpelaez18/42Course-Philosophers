/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:22:58 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/16 15:20:03 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *number)
{
	int			i;
	int			sing;
	int long	result;

	i = 0;
	sing = 1;
	result = 0;
	while ((number[i] >= 9 && number[i] <= 13) || number[i] == 32)
		i++;
	if (number[i] == '+' || number[i] == '-')
	{
		if (number[i] == '-')
			sing = -1;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		result = result * 10 + (number[i] - '0');
		if (result > 2147483648 && sing == -1)
			return (-2);
		else if (result > 2147483647 && sing == 1)
			return (-1);
		i++;
	}
	return ((int)(result * sing));
}

int	non_numeric_parameters(char *param)
{
	int	i;

	i = 0;
	if ((param[i] == '-' || param[i] == '+') && param[i + 1] != '\0')
		i++;
	while (param[i] != '\0')
	{
		if (!is_number(param[i]))
			return (0);
		i++;
	}
	return (1);
}
