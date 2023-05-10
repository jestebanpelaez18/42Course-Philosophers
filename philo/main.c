/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:14:30 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/10 16:52:44 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_vars(char **phi_arg)
{
	
}

int	main(int argc, char **argv)
{
	if (argc != 6 || argc != 5)
	{
		ft_putendl_fd("Error, number of arguments invalid", 2);
		return (0);
	}
	create_vars(argv);
	return (0);
}
