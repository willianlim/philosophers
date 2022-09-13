/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:31:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/13 14:41:21 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

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

# define TRUE 1
# define FALSE 0

typedef enum s_identifier
{
	NUMBER_OF_PHILO = 1,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MEALS_PER_PERSON,
}t_identifier;

typedef struct s_meal
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_per_person;
	long long		start;
	pthread_mutex_t	philo;
	pthread_mutex_t	time;
	pthread_mutex_t	*fork;
}t_meal;

typedef struct s_philo
{
	int			i;
	pthread_t	thread;
	pthread_t	monitoring;
	t_meal		*meal;
	long long	current;
}t_philo;

/**
 * @brief Converts the initial portion of the string pointed
 * to by nptr to int. The behavior is the same as
 * strdol(nptr, NULL, 10).
 *
 * @param nptr Pointer to the area of memory of the string
 * to be converted
 * @return int The converted value or 0 on error
 */
int	ft_atoi(const char *nptr);

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @param meal
 * @return int
 */
int	ft_handling_input(int argc, char *argv[], t_meal *meal);

/**
 * @brief
 *
 * @param meal
 * @param philo
 * @return int
 */
int	ft_prepare_diner(t_meal *meal, t_philo *philo[]);

int	ft_start_diner(t_meal *meal, t_philo *philo);

void	*ft_routine(void *arg);

void	*ft_monitoring(void *arg);

int	ft_stopwatch(long long *value);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_bzero(void *s, size_t n);

void	*ft_memset(void *s, int c, size_t n);

#endif
