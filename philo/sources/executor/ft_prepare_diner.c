/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_diner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:36:39 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/13 16:31:00 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_prepare_diner(t_meal *meal, t_philo **philo)
{
	int	i;

	i = -1;
	(void)philo;
	meal->fork = (pthread_mutex_t *)malloc((meal->number_of_philo) * \
	sizeof(pthread_mutex_t));
	*philo = (t_philo *)malloc((meal->number_of_philo) * sizeof(t_philo));
	printf("entrou no prepare diner\n");
	while (++i < meal->number_of_philo)
		if (pthread_mutex_init(&meal->fork[i], NULL))
			return (FALSE);
	if (pthread_mutex_init(&meal->philo, NULL) || \
	pthread_mutex_init(&meal->time, NULL))
		return (FALSE);
	printf("saiu do prepar diner\n");
	return (TRUE);
}
