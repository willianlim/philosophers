/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:45 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/14 07:10:13 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

int	main(int argc, char *argv[])
{
	t_meal	meal;
	t_philo	*philo;

	philo = NULL;
	memset(&meal, 0, sizeof(t_meal));
	ft_handling_input(argc, argv, &meal);
	ft_prepare_dinner(&meal, &philo);
	ft_start_dinner(&meal, philo);
	return (0);
}
