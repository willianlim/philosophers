/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:45 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/20 16:29:35 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_philo.h"

int	main(int argc, char *argv[])
{
	t_rules	rules;

	memset(&rules, 0, sizeof(t_rules));
	ft_handling_input(argc, argv, &rules);
	ft_prepare_dinner(&rules);
	ft_start_dinner(&rules);
	ft_end_dinner(&rules);
	return (0);
}
