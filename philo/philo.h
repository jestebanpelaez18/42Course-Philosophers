/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:31:01 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/12 18:56:40 by jpelaez-         ###   ########.fr       */
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
}		t_list;

int		ft_atoi(char *number);
int		ft_isdigit(int digit);

void	ft_putendl_fd(char *s, int fd);
void	create_vars(t_list *philo, char **phi_arg, int argc);
#endif