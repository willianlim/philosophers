/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:42:44 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 22:18:03 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_action_print(t_data *data, int id, char *string)
{
	long long	current;

	pthread_mutex_lock(&data->lock_print);
	if (!data->dieded)
	{
		ft_stopwatch(&current);
		printf("%lli ", current - data->starting_stopwatch);
		printf("%i ", id + 1);
		printf("%s", string);
	}
	pthread_mutex_unlock(&data->lock_print);
}
