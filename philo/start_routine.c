/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:53:36 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/24 16:35:31 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(void)
{
    
}

int	start_routine(t_list *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
