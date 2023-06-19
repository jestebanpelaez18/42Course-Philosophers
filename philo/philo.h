/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/06/19 16:01:03 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_list	*info;
	int				identity_n;
	int				eat_count;
	long long		t_last_eat;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	read_updt;
	pthread_t		philo_thr;
}					t_philo;

typedef struct s_list
{
	int				n_philo;
	int				t_die;
	int				t_sleep;
	int				t_eat;
	int				n_times_eat;
	int				dead_philo;
	long long		start_time;
	int				finish_eat;
	int				finish_status;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	read;
	pthread_mutex_t	write;
	t_philo			*philos;
}					t_list;

int					ft_atoi(char *number);
int					non_numeric_parameters(char *param);
int					set_mutex(t_list *info);
int					generate_philos(t_list *info);
int					get_data(t_list *info, char **phi_arg, int argc);
long long			take_time(void);
int					start_routine(t_list *info);

void				ft_sleep(long long time);
void				philosopher_eat(t_philo *philo);
void				philosopher_sleep(t_philo *philo);
void				philo_forks_in_table(t_philo *philo, t_list *info);
void				philo_take_two_fors(t_philo *philo, t_list *info);
void				message(char *str, t_philo *philo);
void				philosopher_think(t_philo *philo);
void				finish_philo(t_list *info);

#endif