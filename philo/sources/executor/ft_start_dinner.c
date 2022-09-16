/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:50:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 22:03:52 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

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
	ft_monitoring(data, data->philosopher);
	return (TRUE);
}
