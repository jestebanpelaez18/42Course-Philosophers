/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:47:04 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/06 22:27:35 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_eat(t_philo *philo)
{
	philo_take_two_fors(philo, philo->info);
	pthread_mutex_lock(&philo->read_updt);
	philo->is_eating = 1;
	philo->t_last_eat = take_time() + philo->info->t_die;
	message("is eating", philo);
	philo->eat_count++;
	ft_sleep(philo->info->t_eat,philo->info);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->read_updt);
	philo_forks_in_table(philo, philo->info);
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
	message("is sleeping",philo);
	ft_sleep(info->t_sleep, info);
}

void	philosopher_think(t_philo *philo)
{
	message("is thinking",philo);
}