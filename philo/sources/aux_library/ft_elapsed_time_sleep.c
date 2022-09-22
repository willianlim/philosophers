/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elapsed_time_sleep.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:00:03 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 10:10:21 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_elapsed_time_sleep(int time_to_sleep)
{
	long long	end;
	long long	start;

	ft_stopwatch(&start);
	ft_stopwatch(&end);
	while (end - start < (long long)time_to_sleep)
	{
		ft_stopwatch(&end);
		usleep(10);
	}
}
