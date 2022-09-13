/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elapse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:15:12 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/13 14:20:30 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_elapse(t_philo *philo, long long begin, long long limit)
{
	long long	current;

	if (!begin)
		if (!ft_stopwatch(&begin))
			pthread_mutex_unlock(&philo->meal->time);
	while (TRUE)
	{
		if (!ft_stopwatch(&current))
			pthread_mutex_unlock(&philo->meal->time);
		if (current - begin >= limit)
			break ;
		if (usleep(1000))
			pthread_mutex_unlock(&philo->meal->time);
	}
}
