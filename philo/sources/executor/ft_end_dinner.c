/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:04:43 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/21 11:48:13 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_end_dinner(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->number_of_philo)
		pthread_join(rules->philosophers[i].thread_id, NULL);
	i = -1;
	while (++i < rules->number_of_philo)
		pthread_mutex_destroy(&rules->philosophers[i].check_mutex);
	i = -1;
	while (++i < rules->number_of_philo)
		pthread_mutex_destroy(&rules->forks[i]);
	pthread_mutex_destroy(&rules->finish_mutex);
	free(rules->forks);
	free(rules->philosophers);
	return (TRUE);
}
