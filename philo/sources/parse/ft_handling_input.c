/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:33:15 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/10 20:54:13 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_init_struct(int index, char *argv, t_meal *meal)
{
	int	number;

	number = ft_atoi(argv);
	if (number > 0)
	{
		if (index == NUMBER_OF_PHILO)
			meal->number_of_philo = number;
		if (index == TIME_TO_DIE)
			meal->time_to_die = number;
		if (index == TIME_TO_EAT)
			meal->time_to_eat = number;
		if (index == TIME_TO_SLEEP)
			meal->time_to_sleep = number;
		if (index == MEALS_PER_PERSON)
			meal->meals_per_person = number;
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_integer_argument_values(int argc, char *argv[], t_meal *meal)
{
	int	index;
	int	with_optional_argv;
	int	mandatory_argv_total;

	index = 0;
	with_optional_argv = 6;
	mandatory_argv_total = 4;
	while (++index <= mandatory_argv_total)
		if (!ft_init_struct(index, argv[index], meal))
			return (FALSE);
	if (argc == with_optional_argv && !ft_init_struct(index, argv[index], meal))
		return (FALSE);
	return (TRUE);
}

int	ft_handling_input(int argc, char *argv[], t_meal *meal)
{
	if (argc < 5 || argc > 6 || !ft_integer_argument_values(argc, argv, meal))
	{
		printf(RED"Error: Number of arguments not allowed\n"RESET);
		exit(EXIT_FAILURE);
	}
	return (TRUE);
}
