/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:41:38 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/16 11:43:29 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

// static void	ft_take_fork(t_data *data, t_philosopher *philo)
// {
// 	pthread_mutex_lock(&data->fork[philo->left_fork]);
// 	ft_action_print(data, philo->id, "has taken a fork\n");
// 	pthread_mutex_lock(&data->fork[philo->right_fork]);
// 	ft_action_print(data, philo->id, "has taken a fork\n");
// }

// static void	ft_break_to_eat(t_data *data, t_philosopher *philo)
// {
// 	pthread_mutex_lock(&data->lock_dinner);
// 	ft_action_print(data, philo->id, "is eating\n");
// 	ft_stopwatch(&philo->last_meal);
// 	pthread_mutex_unlock(&data->lock_dinner);
// }

// static void	ft_put_fork(t_data *data, t_philosopher *philo)
// {
// 	ft_elapsed_time_sleep(data->time_to_eat, data);
// 	++philo->meals_eaten;
// 	pthread_mutex_unlock(&data->fork[philo->left_fork]);
// 	pthread_mutex_unlock(&data->fork[philo->right_fork]);
// }

// static void	ft_time_to_eat(t_philosopher *philo)
// {
// 	t_data	*data;

// 	data = philo->data;
// 	ft_take_fork(data, philo);
// 	ft_break_to_eat(data, philo);
// 	ft_put_fork(data, philo);
// }

static void	ft_time_to_eat(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	ft_action_print(data, philo->id, "has taken a fork\n");
	pthread_mutex_lock(&data->fork[philo->right_fork]);
	ft_action_print(data, philo->id, "has taken a fork\n");
	pthread_mutex_lock(&data->lock_dinner);
	ft_action_print(data, philo->id, "is eating\n");
	ft_stopwatch(&philo->last_meal);
	pthread_mutex_unlock(&data->lock_dinner);
	ft_elapsed_time_sleep(data->time_to_eat, data);
	++philo->meals_eaten;
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
	pthread_mutex_unlock(&data->fork[philo->right_fork]);
}

void	*ft_routine(void *arg_philo)
{
	t_data			*data;
	t_philosopher	*philo;

	philo = (t_philosopher *)arg_philo;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (!data->dieded)
	{
		ft_time_to_eat(philo);
		if (data->all_ate)
			break ;
		ft_action_print(data, philo->id, "is sleeping\n");
		ft_elapsed_time_sleep(data->time_to_sleep, data);
		ft_action_print(data, philo->id, "is thinking\n");
	}
	// free(philo);
	return (NULL);
}
