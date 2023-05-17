/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/17 15:55:08 by jpelaez-         ###   ########.fr       */
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
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_times_eat;
	int				dead_philo;
	pthread_mutex_t	*fork_mutex;
	int				n_dead_philo;
	t_philo			*philos;
}					t_list;

typedef struct s_philo
{
	struct s_list	*gen_data;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
}					t_philo;

int					ft_atoi(char *number);
int					non_numeric_parameters(char *param);
int					set_mutex(t_list *philo);
int					generate_philos(t_list *gen_philo);

void				get_data(t_list *philo, char **phi_arg, int argc);
#endif