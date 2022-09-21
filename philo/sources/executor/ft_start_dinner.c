/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:50:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/21 11:34:00 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_start_dinner(t_rules *rules)
{
	int			i;

	i = -1;
	ft_stopwatch(&rules->starting_stopwatch);
	while (++i < rules->number_of_philo)
	{
		rules->philosophers[i].last_time_to_eat = rules->starting_stopwatch;
		if (pthread_create(&rules->philosophers[i].thread_id, NULL, \
			ft_routine, &rules->philosophers[i]))
		{
			printf(RED"Error: Failed to create a thread for philo\n"RESET);
			return (FALSE);
		}
		if (rules->meals_per_philo == -1)
		{
			if (pthread_create(&rules->philosophers->monitoring_id, NULL, \
				ft_monitoring, &rules->philosophers[i]))
			{
				printf(RED"Error: Failed to create a thread for monitor\n"RESET);
				return (FALSE);
			}
			pthread_detach(rules->philosophers->monitoring_id);
			pthread_join(rules->philosophers->monitoring_id, NULL);
		}
	}
	if (rules->meals_per_philo != -1)
	{
		if (pthread_create(&rules->philosophers->monitoring_id, NULL, \
			ft_monitoring_each_must_each, rules))
		{
			printf(RED"Error: Failed to create a thread for monitor\n"RESET);
			return (FALSE);
		}
		pthread_detach(rules->philosophers->monitoring_id);
		pthread_join(rules->philosophers->monitoring_id, NULL);
	}
	ft_end_dinner(rules);
	return (TRUE);
}
