/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 09:50:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/13 16:30:50 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_start_dinner(t_meal *meal, t_philo *philo)
{
	int	i;

	i = -1;
	puts("1");
	if (pthread_mutex_lock(&meal->time) || \
	!ft_stopwatch(&meal->start))
		return (FALSE);
	puts("2");

	while (++i < meal->number_of_philo)
	{
		puts("entrou no loop");
		philo[i].i = i;
		printf("%d\n", philo[i].i);
		puts("antes do primeiro if");
		if (pthread_create(&philo[i].thread, NULL, ft_routine, \
		(void *)(&philo[i])))
		{
			printf("deu ruim no primeiro if\n");
			return (FALSE);
		}
		puts("antes do segundo if");
		if (pthread_create(&philo[i].monitoring, NULL, ft_monitoring, \
		(void *)(&philo[i])))
			return (FALSE);
	}
	puts("3");
	i = -1;
	while (++i < meal->number_of_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			printf("deu tuim\n");
	}
	puts("4");
	return (TRUE);
}
