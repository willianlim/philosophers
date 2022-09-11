/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:45 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/10 21:08:44 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

int	main(int argc, char *argv[])
{
	t_meal	meal;

	memset(&meal, 0, sizeof(t_meal));
	ft_handling_input(argc, argv, &meal);
	return (0);
}
