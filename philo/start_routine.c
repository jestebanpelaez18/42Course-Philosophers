/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:53:36 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/05 13:39:11 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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
		if (take_time() >= check_info->t_die && philo->is_eating == 0)
			message("died", philo);
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
	return (1);
}
