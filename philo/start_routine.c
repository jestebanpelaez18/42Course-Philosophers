/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:53:36 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/15 15:39:32 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	finish_philo(t_list *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		pthread_mutex_destroy(&info->philos[i].read_updt);
		i++;
	}
	pthread_mutex_destroy(&info->write);
	pthread_mutex_destroy(&info->read);
	free(info->philos);
	free(info->fork_mutex);
}

void	check_df(t_list *info)
{
	int			i;
	long long	current;

	while (info->finish_status != 1)
	{
		if (info->n_times_eat != 0 && info->finish_eat == info->n_philo)
		{
			info->finish_status = 1;
			break ;
		}
		i = 0;
		while (i < info->n_philo)
		{
			pthread_mutex_lock(&info->read);
			if (take_time()
				- info->philos[i].t_last_eat >= (long long)info->t_die)
			{
				message("died", &info->philos[i]);
				info->finish_status = 1;
				break ;
			}
			pthread_mutex_unlock(&info->read);
			i++;
		}
	}
}

void	*routine(void *info)
{
	t_list	*r_info;
	t_philo	*philosopher;

	philosopher = info;
	r_info = philosopher->info;
	philosopher->t_last_eat = take_time();
	if (philosopher->identity_n % 2)
		ft_sleep(r_info->t_eat / 50, r_info);
	while (r_info->finish_status != 1)
	{
		philosopher_eat(philosopher);
		if (r_info->n_times_eat != 0
			&& r_info->n_times_eat == philosopher->eat_count)
		{
			r_info->finish_eat++;
			break ;
		}
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
	return ((void *)0);
}

int	start_routine(t_list *info)
{
	int	i;
	int	j;

	i = 0;
	info->start_time = take_time();
	while (i < info->n_philo)
	{
		if (pthread_create(&info->philos[i].philo_thr, NULL, &routine,
				&(info->philos[i])))
			return (0);
		i++;
	}
	check_df(info);
	j = 0;
	while (j < info->n_philo)
	{
		if (pthread_join(info->philos[j].philo_thr, NULL))
			return (0);
		j++;
	}
	finish_philo(info);
	return (1);
}
