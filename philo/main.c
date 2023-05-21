/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:14:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/21 11:55:05 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arguments(char **arguments, int n_arg)
{
	int	i;
	int	j;

	i = 1;
	if (n_arg != 5 && n_arg != 6)
	{
		printf("Error, invalid number of arguments\n");
		return (0);
	}
	while (arguments[i] != NULL)
	{
		if (!non_numeric_parameters(arguments[i]))
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
	t_list	info;

	if(!check_arguments(argv, argc))
		return (0);
	if(!get_data(&info, argv, argc));
		return(0);
	if(!set_mutex(&info))
		return (0);
	if(!generate_philos(&info))
		return (0);
	if(!start_routine(&info))
		return(0);
	return (0);
}
