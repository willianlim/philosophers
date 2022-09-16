/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_dinner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:36:39 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 18:22:23 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_init_forks(t_data *data)
{
	int	i;

	i = -1;
	data->fork = (pthread_mutex_t *)malloc(data->number_of_philo * \
	sizeof(pthread_mutex_t));
	if (data->fork == NULL)
	{
		printf(RED"Failed to alloc forks\n"RESET);
		return (FALSE);
	}
	while (++i < data->number_of_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
		{
			printf(RED"Failed to init mutex fork\n"RESET);
			return (FALSE);
		}
	}
	if (pthread_mutex_init(&data->lock_print, NULL) || \
	pthread_mutex_init(&data->lock_dinner, NULL))
	{
		printf(RED"Failed to init mutex 'lock_print' or 'lock_dinner'\n"RESET);
		return (FALSE);
	}
	return (TRUE);
}

static int	ft_init_philosophers(t_data *data)
{
	int	i;

	i = -1;
	data->philosopher = (t_philosopher *)malloc(data->number_of_philo * \
	sizeof(t_philosopher));
	if (data->philosopher == NULL)
	{
		printf(RED"Failed to alloc philosophers\n"RESET);
		return (FALSE);
	}
	while (++i < data->number_of_philo)
	{
		data->philosopher[i].id = i;
		data->philosopher[i].meals_eaten = 0;
		data->philosopher[i].left_fork = i;
		data->philosopher[i].right_fork = (i + 1) % data->number_of_philo;
		data->philosopher[i].last_meal = 0;
		data->philosopher[i].data = data;
	}
	return (TRUE);
}

int	ft_prepare_dinner(t_data *data)
{
	if (!ft_init_forks(data) || !ft_init_philosophers(data))
		return (FALSE);
	return (TRUE);
}
