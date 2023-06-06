/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:12:42 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/06 22:29:24 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	take_time(void)
{
	struct timeval	current_time;

	if(gettimeofday(&current_time, NULL))
		return (0);
	return ((current_time.tv_sec * (long long)1000) + (current_time.tv_usec / 1000));
}

void message(char *str, t_philo *philo)
{
	int  timestamp;
	
	timestamp = take_time() - philo->info->start_time;
	if(philo->info->finish_status != 1)
	{
		pthread_mutex_lock(&philo->info->write);
		printf("%d %d %s\n", timestamp, philo->identity_n, str);
		pthread_mutex_unlock(&philo->info->write);
	}
}

void    ft_sleep(long long time, t_list *info)
{
    long long start;

    start = take_time();
    while(!info->finish_status)
    {
        if(take_time() - start >= time)
            break ;
        usleep(10);
    }
}