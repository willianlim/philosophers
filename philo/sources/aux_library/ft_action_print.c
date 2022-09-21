/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:42:44 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/20 11:08:14 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static void	ft_coloring_print(char *str)
{
	if (!ft_strcmp(str, "has taken a fork\n"))
		printf(YELLOW"has taken a fork\n"RESET);
	else if (!ft_strcmp(str, "is sleeping\n"))
		printf(CYAN"is sleeping\n"RESET);
	else if (!ft_strcmp(str, "is thinking\n"))
		printf(MAGENTA"is thinking\n"RESET);
	else
		printf(RED"died\n"RESET);
}

void	ft_action_print(t_philosopher *philo, char *string)
{
	long long	current;

	pthread_mutex_lock(&philo->rules->finish_mutex);
	ft_stopwatch(&current);
	if (!philo->rules->finish)
	{
		printf("%lli\t", current - philo->rules->starting_stopwatch);
		printf("%i\t", philo->id + 1);
		ft_coloring_print(string);
	}
	pthread_mutex_unlock(&philo->rules->finish_mutex);
}
