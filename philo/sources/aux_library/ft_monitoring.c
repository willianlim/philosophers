/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:58:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/16 13:50:12 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_monitoring(t_data *data, t_philosopher *philo)
{
	int			i;
	long long	current;

	while (!data->all_ate)
	{
		i = -1;
		while (++i < data->number_of_philo && !data->dieded)
		{
			pthread_mutex_lock(&data->lock_dinner);
			ft_stopwatch(&current);
			if ((current - philo[i].last_meal) > data->time_to_die)
			{
				ft_action_print(data, i, "died\n");
				data->dieded = TRUE;
				// data->all_ate = TRUE;
				return (FALSE);
			}
			pthread_mutex_unlock(&data->lock_dinner);
			printf("sai do if\n");
			// usleep(100);
		}
		if (data->dieded)
		{
			printf("entrei no if do died\n");
			return (FALSE);
		}
		i = 0;
		while (data->meals_per_person != -1 && i < data->number_of_philo && \
		philo[i].meals_eaten >= data->meals_per_person)
			i++;
		if (i == data->number_of_philo)
			data->all_ate = TRUE;
	}
	printf("sai do monitoring \n");
	return (TRUE);
}
