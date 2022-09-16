/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:04:43 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/16 13:47:39 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_end_dinner(t_data *data, t_philosopher *philo)
{
	int	i;

	printf("entre no end dinner\n");
	i = 0;
	while (i < data->number_of_philo)
	{
		printf("estou no join\n");
		pthread_join(philo[i++].thread, NULL);
	}
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
	// free(philo->data->fork);
	// free(philo->data->philosopher);
	// i = -1;
	// while (++i < data->number_of_philo)
	// {
	// 	free(&philo[i]);
	// }
	printf("Terminei o end dinner\n");
	return (TRUE);
}
