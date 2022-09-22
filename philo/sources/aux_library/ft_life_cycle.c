/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:52:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 11:59:27 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_action_print(philo, "has taken a fork\n");
	pthread_mutex_lock(philo->left_fork);
	ft_action_print(philo, "has taken a fork\n");
}

void	ft_eat(t_philosopher *philo)
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
	ft_elapsed_time_sleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(&philo->rules->finish_mutex);
}

void	ft_put_fork(t_philosopher *philo)
{
	ft_elapsed_time_sleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->check_mutex);
}

void	ft_sleep(t_philosopher *philo)
{
	ft_action_print(philo, "is sleeping\n");
	ft_elapsed_time_sleep(philo->rules->time_to_eat);
}

void	ft_think(t_philosopher *philo)
{
	ft_action_print(philo, "is thinking\n");
	usleep(500);
}