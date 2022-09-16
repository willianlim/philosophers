/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:04:43 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 22:24:44 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_end_dinner(t_data *data, t_philosopher *philo)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philo)
	{
		pthread_join(philo[i].thread, NULL);
		// if (pthread_join(philo[i].thread, NULL))
		// {
		// 	printf(RED"Erro: Failed join\n"RESET);
		// 	return (FALSE);
		// }
	}
	i = -1;
	while (++i < data->number_of_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		// if (pthread_mutex_destroy(&data->fork[i]))
		// {
		// 	printf(RED"Error: Failed destroy mutex\n"RESET);
		// 	return (FALSE);
		// }
	}
	pthread_mutex_destroy(&data->lock_print);
	pthread_mutex_destroy(&data->lock_dinner);
	// if (pthread_mutex_destroy(&data->lock_print) || 
	// pthread_mutex_destroy(&data->lock_dinner))
	// {
	// 	printf(RED"Error: Failed destroy mutex\n"RESET);
	// 	return (FALSE);
	// }
	return (TRUE);
}
