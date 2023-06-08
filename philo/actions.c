/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:47:04 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/08 13:23:40 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_eat(t_philo *philo)
{
	if(philo->info->finish_status != 1)
	{
		philo_take_two_fors(philo, philo->info);
		pthread_mutex_lock(&philo->read_updt);
		philo->is_eating = 1;
		philo->t_last_eat = take_time();
		message("is eating", philo);
		philo->eat_count++;
		ft_sleep(philo->info->t_eat,philo->info);
		philo->is_eating = 0;
		pthread_mutex_unlock(&philo->read_updt);
		philo_forks_in_table(philo, philo->info);
	}
}

void	philo_take_two_fors(t_philo *philo, t_list *info)
{
	pthread_mutex_lock(&info->fork_mutex[philo->l_fork]);
	message("has taken a fork", philo);
	pthread_mutex_lock(&info->fork_mutex[philo->r_fork]);
	message("has taken a fork", philo);
}

void	philo_forks_in_table(t_philo *philo, t_list *info)
{
	pthread_mutex_unlock(&info->fork_mutex[philo->l_fork]);
	pthread_mutex_unlock(&info->fork_mutex[philo->r_fork]);
}

void	philosopher_think(t_philo *philo)
{
	if(philo->info->finish_status != 1)
		message("is thinking",philo);
}

void	philosopher_sleep(t_philo *philo)
{
	if(philo->info->finish_status != 1)
	{
		message("is sleeping",philo);
		ft_sleep(philo->info->t_sleep, philo->info);
	}
}