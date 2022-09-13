/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:58:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/13 16:32:00 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_monitoring(void *arg)
{
	t_philo		*philo;
	long long	current;

	puts("estou em monitoring");
	philo = (t_philo *)arg;
	while (TRUE)
	{
		if (!ft_stopwatch(&current))
			pthread_mutex_unlock(&philo->meal->time);
		if (current - philo->current > (long long)philo->meal->time_to_die)
		{
			puts("estou no monitoring");
			pthread_mutex_unlock(&philo->meal->time);
		}
	}
	return (NULL);
}
