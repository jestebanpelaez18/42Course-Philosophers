/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/13 16:47:56 by jpelaez-         ###   ########.fr       */
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
int		ft_isdigit(int digit);
int		set_mutex(t_list *philo);

void	create_vars(t_list *philo, char **phi_arg, int argc);
void	init_philo(t_list *philo, char **phi_arg, int argc);
#endif