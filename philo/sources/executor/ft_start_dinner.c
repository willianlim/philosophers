/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:50:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/16 14:24:17 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_finish_dinner(t_data *data, t_philosopher *philo)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		printf("estou no destroy\n");
		pthread_mutex_destroy(&data->fork[i]);
	}
	pthread_mutex_destroy(&data->lock_dinner);
	pthread_mutex_destroy(&data->lock_print);
	// i = -1;
	// while (++i < data->number_of_philo)
	// {
	// 	free(&data->fork);
	// 	free(&data->philosopher);
	// }
	free(data->fork);
	free(data->philosopher);
	free(philo);
	// free(philo->data->fork);
	// free(philo->data->philosopher);
}

int	ft_start_dinner(t_data *data, t_philosopher *philo)
{
	int	i;

	i = -1;
	memset(philo, 0, sizeof(t_philosopher));
	philo = data->philosopher;
	ft_stopwatch(&data->starting_stopwatch);
	while (++i < data->number_of_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]))
		{
			printf(RED"Error: Failed to create a thread for philo\n"RESET);
			return (FALSE);
		}
		ft_stopwatch(&philo[i].last_meal);
	}
	if (ft_monitoring(data, data->philosopher))
		ft_end_dinner(data, philo);
	else
		ft_finish_dinner(data, philo);
	return (TRUE);
}
