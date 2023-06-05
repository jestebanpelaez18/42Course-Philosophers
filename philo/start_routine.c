/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:53:36 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/05 15:12:41 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void finish_philo(t_list *info)
{
	int i;

	i = 0;
	while(i < info->n_philo)
	{
		pthread_mutex_destroy(&info->fork_mutex[i]);
		pthread_mutex_destroy((*info).philos[i].read_updt);
	}
	pthread_mutex_destroy(&info->write);
	free(info->philos);
	free(info->fork_mutex);
}

void check_df(void *info)
{
	t_philo *philo;
	t_list *check_info;
	
	philo = info;
	check_info = philo->info;
	while(check_info->finish_status != 1)
	{
		pthread_mutex_lock(&philo->read_updt);
		if(check_info->n_times_eat != -1 && check_info->finish_eat == check_info->n_philo)
			check_info->finish_status = 1;
		if (take_time() - philo->t_last_eat >= check_info->t_die && philo->is_eating == 0)
		{
			message("died", philo);
			check_info->finish_status = 1;
		}
		pthread_mutex_unlock(&philo->read_updt);
	}
}
void	routine(void *info)
{
	t_list	*r_info;
	t_philo	*philosopher;

	philosopher = info;
	r_info = philosopher->info;
	if (pthread_create(&philosopher->checker, NULL, &check_df, &philosopher))
		return ;
	while (r_info->finish_status != 1)
	{
		philosopher_eat(philosopher);
		if (r_info->n_times_eat != -1
			&& r_info->n_times_eat == philosopher->eat_count)
			{
				r_info->finish_eat++;
				break ;
			}
		philosopher_think(philosopher);
	}
	if(pthread_join(philosopher->checker, NULL));
		return ;
}

int	start_routine(t_list *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->start_time = take_time();
	while (i < info->n_philo)
	{
		if (pthread_create(&((*info).philos[i].philo_thr), NULL, &routine,
				&(info->philos[i])))
			return (0);
		i++;
	}
	while (j < info->n_philo)
	{
		if (pthread_join((*info).philos[i].philo_thr, NULL))
			return (0);
		j++;
	}
	finish_philo(info);
	return (1);
}

