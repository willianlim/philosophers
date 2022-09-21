/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:33:15 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/19 14:06:08 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_init_struct(int index, char *argv, t_rules *rules)
{
	int	number;

	number = ft_atoi(argv);
	if (number > 0)
	{
		if (index == NUMBER_OF_PHILO)
			rules->number_of_philo = number;
		if (index == TIME_TO_DIE)
			rules->time_to_die = number;
		if (index == TIME_TO_EAT)
			rules->time_to_eat = number;
		if (index == TIME_TO_SLEEP)
			rules->time_to_sleep = number;
		if (index == MEALS_PER_PERSON)
			rules->meals_per_philo = number;
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_integer_argument_values(int argc, char *argv[], t_rules *rules)
{
	int	index;
	int	with_optional_argv;
	int	mandatory_argv_total;

	index = 0;
	with_optional_argv = 6;
	mandatory_argv_total = 4;
	while (++index <= mandatory_argv_total)
		if (!ft_init_struct(index, argv[index], rules))
			return (FALSE);
	if (argc == with_optional_argv && \
	!ft_init_struct(index, argv[index], rules))
		return (FALSE);
	else if (argc == mandatory_argv_total + 1)
		rules->meals_per_philo = -1;
	return (TRUE);
}

int	ft_handling_input(int argc, char *argv[], t_rules *rules)
{
	if (argc < 5 || argc > 6)
	{
		printf(RED"Error: Number of arguments not allowed\n"RESET);
		return (FALSE);
	}
	if (!ft_integer_argument_values(argc, argv, rules))
	{
		printf(RED"Error: "RESET);
		printf(RED"One of the values entered is not a positive integer\n"RESET);
		return (FALSE);
	}
	return (TRUE);
}
