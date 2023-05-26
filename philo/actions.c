/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:47:04 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/26 17:34:04 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	philo_take_two_fors(philo);
	pthread_mutex_lock(&philo->read_updt);
	philo->is_eating = 1;
	// message is eating
	philo->eat_count++;
	usleep(philo->info->t_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->read_updt);
	philo_forks_in_table(philo);
}

void	philo_sleep(t_philo *philo)
{
}

void	philo_take_two_fors(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
}

void	philo_forks_in_table(t_philo *philo)
{
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(&philo->r_fork);
	philo_sleep(philo);
	// message is sleeping
	usleep(philo->info->t_sleep);
	// philo is thinking
}
