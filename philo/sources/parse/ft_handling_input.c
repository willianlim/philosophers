/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:33:15 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 18:02:01 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_init_struct(int index, char *argv, t_data *data)
{
	int	number;

	number = ft_atoi(argv);
	if (number > 0)
	{
		if (index == NUMBER_OF_PHILO)
			data->number_of_philo = number;
		if (index == TIME_TO_DIE)
			data->time_to_die = number;
		if (index == TIME_TO_EAT)
			data->time_to_eat = number;
		if (index == TIME_TO_SLEEP)
			data->time_to_sleep = number;
		if (index == MEALS_PER_PERSON)
			data->meals_per_person = number;
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_integer_argument_values(int argc, char *argv[], t_data *data)
{
	int	index;
	int	with_optional_argv;
	int	mandatory_argv_total;

	index = 0;
	with_optional_argv = 6;
	mandatory_argv_total = 4;
	while (++index <= mandatory_argv_total)
		if (!ft_init_struct(index, argv[index], data))
			return (FALSE);
	if (argc == with_optional_argv && !ft_init_struct(index, argv[index], data))
		return (FALSE);
	else if (argc == mandatory_argv_total + 1)
		data->meals_per_person = -1;
	return (TRUE);
}

int	ft_handling_input(int argc, char *argv[], t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf(RED"Error: Number of arguments not allowed\n"RESET);
		return (FALSE);
	}
	if (!ft_integer_argument_values(argc, argv, data))
	{
		printf(RED"Error: "RESET);
		printf(RED"One of the values entered is not a positive integer\n"RESET);
		return (FALSE);
	}
	return (TRUE);
}
