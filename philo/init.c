/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:12:59 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/26 17:07:12 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_data(t_list *info, char **phi_arg, int argc)
{
	info->n_philo = ft_atoi(phi_arg[1]);
	info->t_die = ft_atoi(phi_arg[2]);
	info->t_eat = ft_atoi(phi_arg[3]);
	info->t_sleep = ft_atoi(phi_arg[4]);
	info->dead_philo = 0;
	if (argc == 6)
		info->n_times_eat = ft_atoi(phi_arg[5]);
	else
		info->n_times_eat = -1;
	if (info->n_philo <= 0 || info->t_die <= 0 || info->t_eat <= 0
		|| info->t_sleep <= 0)
	{
		printf("Error, not valid arguments");
		return (0);
	}
	return (1);
}

int	set_mutex(t_list *info)
{
	int	i;

	i = 0;
	info->fork_mutex = malloc(sizeof(pthread_mutex_t) * (info->n_philo));
	if (!info->fork_mutex)
		return (0);
	while (i < info->n_philo)
	{
		if (pthread_mutex_init(&info->fork_mutex[i], NULL))
			return (0);
		i++;
	}
	if (pthread_mutex_init(&info->read, NULL))
		return (0);
	return (1);
}

int	generate_philos(t_list *info)
{
	int i;

	i = 0;
	info->philos = malloc(sizeof(t_philo) * (info->n_philo));
	if (!info->philos)
		return (0);
	while (i < info->n_philo)
	{
		(*info).philos[i].info = info;
		(*info).philos[i].eat_count = 0;
		(*info).philos[i].identity_n = i + 1;
		(*info).philos[i].l_fork = i;
		(*info).philos[i].r_fork = ((i + 1) % info->n_philo);
		pthread_mutex_init((*info).philos[i].read_updt, NULL);
		i++;
	}
	return (1);
}