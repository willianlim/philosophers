/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:41:38 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 11:56:02 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2)
		ft_elapsed_time_sleep(5);
	while (!philo->rules->finish)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_put_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
