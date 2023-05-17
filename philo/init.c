/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:12:59 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/17 15:11:03 by jpelaez-         ###   ########.fr       */
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
	int	i;

	i = 0;
	philo->fork_mutex = malloc(sizeof(pthread_mutex_t) * (philo->n_philo));
	if (!philo->fork_mutex)
		return (0);
	while (i < philo->n_philo)
	{
		pthread_mutex_init(&philo->fork_mutex[i], NULL);
		i++;
	}
}
