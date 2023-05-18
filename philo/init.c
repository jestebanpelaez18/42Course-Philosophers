/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:12:59 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/18 18:07:50 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_data(t_list *gen_philo, char **phi_arg, int argc)
{
	gen_philo->n_philo = ft_atoi(phi_arg[1]);
	gen_philo->t_die = ft_atoi(phi_arg[2]);
	gen_philo->t_eat = ft_atoi(phi_arg[3]);
	gen_philo->t_sleep = ft_atoi(phi_arg[4]);
	gen_philo->n_dead_philo = 0;
	if (argc == 6)
		gen_philo->n_times_eat = ft_atoi(phi_arg[5]);
	else
		gen_philo->n_times_eat = -1;
	if(gen_philo->n_philo <= 0 || gen_philo->t_die <= 0 || gen_philo->t_eat <= 0 ||  gen_philo->t_sleep <= 0)
	{
		printf("Error, not valid arguments");
		return (0);
	}
	gen_philo->dead_philo = 0;
}

int	set_mutex(t_list *gen_philo)
{
	int	i;

	i = 0;
	gen_philo->fork_mutex = malloc(sizeof(pthread_mutex_t)
			* (gen_philo->n_philo));
	if (!gen_philo->fork_mutex)
		return (0);
	while (i < gen_philo->n_philo)
	{
		pthread_mutex_init(&gen_philo->fork_mutex[i], NULL);
		i++;
	}
	return (1);
}

int	generate_philos(t_list *gen_philo)
{
	int i;

	i = 0;
	gen_philo->philos = malloc(sizeof(t_philo) * (gen_philo->n_philo));
	if (!gen_philo->philos)
		return (0);
	while (i < gen_philo->n_philo)
	{
		(*gen_philo).philos[i].t_eat = gen_philo->t_eat;
		(*gen_philo).philos[i].t_sleep = gen_philo->t_sleep;
		(*gen_philo).philos[i].t_eat = gen_philo->t_sleep;
		(*gen_philo).philos[i].identity_n = i + 1;
		(*gen_philo).philos[i].l_fork = i;
		(*gen_philo).philos[i].r_fork = i + 1;		
		i++;
	}
}