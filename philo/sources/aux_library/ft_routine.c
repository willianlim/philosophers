/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:41:38 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/21 12:14:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_action_print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->left_fork);
	ft_action_print(philo, "has taken a fork\n");
}

static void	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->check_mutex);
	ft_stopwatch(&philo->last_time_to_eat);
	pthread_mutex_lock(&philo->rules->finish_mutex);
	if (!philo->rules->finish)
	{
		printf("%lli\t", philo->last_time_to_eat - \
		philo->rules->starting_stopwatch);
		printf("%i\t", philo->id + 1);
		printf(GREEN"is eating\n"RESET);
	}
	if (++philo->meals_eaten == philo->rules->meals_per_philo)
		philo->rules->number_of_eat_finish_philo++;
	pthread_mutex_unlock(&philo->rules->finish_mutex);
}

static void	ft_put_fork(t_philosopher *philo)
{
	usleep(philo->rules->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->check_mutex);
}

static void	ft_sleep(t_philosopher *philo)
{
	ft_action_print(philo, "is sleeping\n");
	usleep(philo->rules->time_to_sleep * 1000);
}

static void	ft_think(t_philosopher *philo)
{
	ft_action_print(philo, "is thinking\n");
}

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2)
		usleep(philo->rules->time_to_eat * 1000);
	while (!philo->rules->finish)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_put_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
