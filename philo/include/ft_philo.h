/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:30:51 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/10 15:36:58 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define BLACK "\e[30;1m"
# define RED "\e[31;1m"
# define GREEN "\e[32;1m"
# define YELLOW "\e[33;1m"
# define BLUE "\e[34;1m"
# define MAGENTA "\e[35;1m"
# define CYAN "\e[36;1m"
# define WHITE "\e[37;1m"
# define RESET "\e[0m"

typedef struct	s_meal
{
	int	number_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	meals_per_person;
}t_meal;

int	ft_handling_input(int argc, char *argv[]);

#endif
