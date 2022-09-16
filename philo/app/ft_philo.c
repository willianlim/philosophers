/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:45 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 22:03:31 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philosopher	philo;

	memset(&data, 0, sizeof(t_data));
	ft_handling_input(argc, argv, &data);
	ft_prepare_dinner(&data);
	ft_start_dinner(&data, &philo);
	ft_end_dinner(&data, &philo);
	return (0);
}
