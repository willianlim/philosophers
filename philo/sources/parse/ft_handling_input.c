/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handling_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:33:15 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/10 17:23:27 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_handling_input(int argc, char *argv[])
{
	(void)argv;
	if (argc < 5 || argc > 6)
	{
		printf(RED"Error: Number of arguments not allowed\n"RESET);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
