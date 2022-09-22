/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:41:38 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 18:07:30 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*ft_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		ft_elapsed_time_sleep(5);
	if (philo->rules->number_of_philo == 1)
	{
		ft_action_print(philo, "has taken a fork\n");
		ft_elapsed_time_sleep(philo->rules->time_to_die);
		return (NULL);
	}
	while (!philo->rules->finish)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_put_fork(philo);
		if (philo->meals_eaten == philo->rules->meals_per_philo)
			return (NULL);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
