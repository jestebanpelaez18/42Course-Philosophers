/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/16 15:20:19 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_list
{
	int	n_philo;
	int	t_die;
	int	t_sleep;
	int	t_eat;
	int	n_times_eat;
	int	fork_mutex;
	int	n_dead_philo;
}		t_list;

int		ft_atoi(char *number);
int		non_numeric_parameters(char *param);
int		set_mutex(t_list *philo);

void	create_vars(t_list *philo, char **phi_arg, int argc);
void	init_philo(t_list *philo, char **phi_arg, int argc);
#endif