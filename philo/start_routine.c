/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:53:36 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/25 18:13:36 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void *info)
{
    t_list *r_info;
	t_philo *philosopher;

	philosopher = info;
	r_info = philosopher->info;
	while(r_info->finish_status != 1)
	{
		
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
