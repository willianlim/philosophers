/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_dinner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:36:39 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 09:35:19 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_init_forks(t_rules *rules)
{
	int	i;

	i = -1;
	rules->forks = (pthread_mutex_t *)malloc(rules->number_of_philo * \
		sizeof(pthread_mutex_t));
	if (rules->forks == NULL)
	{
		printf(RED"Failed to alloc forks\n"RESET);
		return (FALSE);
	}
	while (++i < rules->number_of_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL))
		{
			printf(RED"Failed to init mutex forks\n"RESET);
			return (FALSE);
		}
	}
	return (TRUE);
}

static int	ft_init_philosophers(t_rules *rules)
{
	int	i;

	i = -1;
	rules->philosophers = (t_philosopher *)malloc(rules->number_of_philo * \
		sizeof(t_philosopher));
	if (rules->philosophers == NULL)
	{
		puts("deui ruim na alocação do philo");
		return (FALSE);
	}
	while (++i < rules->number_of_philo)
	{
		pthread_mutex_init(&rules->philosophers[i].check_mutex, NULL);
		rules->philosophers[i].id = i;
		rules->philosophers[i].meals_eaten = 0;
		rules->philosophers[i].left_fork = &rules->forks[i];
		rules->philosophers[i].right_fork = &rules->forks[(i + 1) % rules->number_of_philo];
		rules->philosophers[i].rules = rules;
	}
	return (TRUE);
}

int	ft_prepare_dinner(t_rules *rules)
{
	pthread_mutex_init(&rules->finish_mutex, NULL);
	if (!ft_init_forks(rules) || !ft_init_philosophers(rules))
		return (FALSE);
	return (TRUE);
}
