/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stopwatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:28:32 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/13 14:41:15 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_stopwatch(long long *value)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (FALSE);
	*value = (long long)(time.tv_sec * 1000 + time.tv_usec / 1000);
	return (TRUE);
}
