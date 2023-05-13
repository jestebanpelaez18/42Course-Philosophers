/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:14:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/13 16:49:05 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arguments(char **arguments, int n_arg)
{
	int	i;
	int	j;

	i = 0;
	if (n_arg != 6 || n_arg != 5)
	{
		printf("Error, invalid arguments\n");
		return (0);
	}
	while (arguments[i] != NULL)
	{
		if (!ft_isdigit(ft_atoi(arguments[i])))
		{
			printf("Error, invalid arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	philo;

	if (!check_arguments(argv, argc))
		return (0);
	init_philo(&philo, argv, argc);
	// if (!set_mutex(&philo))
	// 	return (0);
	return (0);
}
