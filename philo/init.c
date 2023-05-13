/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:12:59 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/13 16:38:12 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_list *philo, char **phi_arg, int argc)
{
	philo->n_philo = ft_atoi(phi_arg[1]);
	philo->t_die = ft_atoi(phi_arg[2]);
	philo->t_eat = ft_atoi(phi_arg[3]);
	philo->t_sleep = ft_atoi(phi_arg[4]);
	philo->n_dead_philo = 0;
	if (argc == 6)
		philo->n_times_eat = ft_atoi(phi_arg[5]);
	else
		philo->n_times_eat = 0;
}

int	set_mutex(t_list *philo)
{
	philo->fork_mutex = malloc(sizeof(int) * (philo->n_philo));
	if (!philo->fork_mutex)
		return (0);
}
