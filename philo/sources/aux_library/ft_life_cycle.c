/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life_cycle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:52:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 18:00:20 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	if (!philo->rules->finish)
	{
		ft_action_print(philo, "has taken a fork\n");
		ft_action_print(philo, "has taken a fork\n");
		return ;
	}
}

void	ft_eat(t_philosopher *philo)
{
	ft_stopwatch(&philo->last_time_to_eat);
	if (!philo->rules->finish)
		ft_action_print(philo, "is eating\n");
	pthread_mutex_lock(&philo->check_mutex);
	if (++philo->meals_eaten == philo->rules->meals_per_philo)
		philo->rules->number_of_eat_finish_philo++;
	pthread_mutex_unlock(&philo->check_mutex);
	ft_elapsed_time_sleep(philo->rules->time_to_eat);
}

void	ft_put_fork(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_sleep(t_philosopher *philo)
{
	ft_action_print(philo, "is sleeping\n");
	ft_elapsed_time_sleep(philo->rules->time_to_sleep);
}

void	ft_think(t_philosopher *philo)
{
	ft_action_print(philo, "is thinking\n");
	usleep(5);
}
