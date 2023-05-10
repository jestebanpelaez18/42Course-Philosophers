/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:12:59 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/10 17:20:41 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_list *philo, char **phi_arg)
{
	philo->n_philo = ft_atoi(phi_arg[1]);
	philo->t_die = ft_atoi(phi_arg[2]);
	philo->t_eat = ft_atoi(phi_arg[3]);
	philo->t_sleep = ft_atoi(phi_arg[4]);
}
