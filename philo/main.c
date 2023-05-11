/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:14:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/11 18:25:29 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_arguments(char **arguments)
{
	int i;
	int j;

	i = 0;
	while(arguments[i] != NULL)
	{
		j = 0;
		while (arguments[i][j] != '\0')
		{
			if(!ft_isdigit(ft_atoi(arguments[i][j])));
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	philo;

	if (argc != 6 || argc != 5)
	{
		ft_putendl_fd("Error, number of arguments invalid", 2);
		return (0);
	}
	if(!check_arguments(**argv));
	{
		ft_putendl_fd("Error, invalid arguments", 2);
		return (0);
	}
	init_philo(&philo, argv, argc);
	return (0);
}
