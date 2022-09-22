/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:58:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 20:24:01 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_monitoring_each_must_each(void *arg)
{
	t_rules	*rules;

	rules = (t_rules *)arg;
	while (!rules->finish)
	{
		pthread_mutex_lock(&rules->finish_mutex);
		if (rules->number_of_eat_finish_philo == rules->number_of_philo)
			rules->finish = TRUE;
		pthread_mutex_unlock(&rules->finish_mutex);
	}
	return (NULL);
}

void	*ft_monitoring(void *arg)
{
	long			current;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->rules->finish)
	{
		pthread_mutex_lock(&philo->check_mutex);
		pthread_mutex_lock(&philo->rules->finish_mutex);
		ft_stopwatch(&current);
		if ((current - philo->last_time_to_eat) >= philo->rules->time_to_die \
			&& !philo->rules->finish)
		{
			printf("%li\t", current - philo->rules->starting_stopwatch);
			printf("%i\t", philo->id + 1);
			printf(RED"died\n"RESET);
			philo->rules->finish = TRUE;
		}
		pthread_mutex_unlock(&philo->rules->finish_mutex);
		pthread_mutex_unlock(&philo->check_mutex);
		ft_elapsed_time_sleep(2);
	}
	return (NULL);
}
