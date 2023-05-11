/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:22:58 by jpelaez-          #+#    #+#             */
/*   Updated: 2023/05/11 18:19:36 by jpelaez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_atoi(char *number)
{
	int			i;
	int			sing;
	int long	result;

	i = 0;
	sing = 1;
	result = 0;
	while ((number[i] >= 9 && number[i] <= 13) || number[i] == 32)
		i++;
	if (number[i] == '+' || number[i] == '-')
	{
		if (number[i] == '-')
			sing = -1;
		i++;
	}
	while (number[i] >= '0' && number[i] <= '9')
	{
		result = result * 10 + (number[i] - '0');
		if (result > 2147483648 && sing == -1)
			return (-2);
		else if (result > 2147483647 && sing == 1)
			return (-1);
		i++;
	}
	return ((int)(result * sing));
}

int	ft_isdigit(int digit)
{
	if (digit >= 48 && digit <= 57)
		return (1);
	else
		return (0);
}