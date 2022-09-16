/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elapsed_time_sleep.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:15:12 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 22:19:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

// sugestão de tempo ft_elapsed_time();
void	ft_elapsed_time_sleep(int time_to_sleep, t_data *data)
{
	long long	end;
	long long	start;

	ft_stopwatch(&start);
	while (!data->dieded)
	{
		ft_stopwatch(&end);
		if (end - start >= time_to_sleep)
			break ;
		usleep(50);
	}
}
