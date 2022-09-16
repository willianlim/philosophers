/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:31:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/15 22:15:51 by wrosendo         ###   ########.fr       */
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

struct s_data;

typedef enum s_identifier
{
	NUMBER_OF_PHILO = 1,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	MEALS_PER_PERSON,
}t_identifier;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	struct s_data	*data;
	pthread_t		thread;
}t_philosopher;

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_per_person;
	int				dieded;
	int				all_ate;
	long long		starting_stopwatch;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_dinner;
	pthread_mutex_t	*fork;
	t_philosopher	*philosopher;
}t_data;

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
int	ft_handling_input(int argc, char *argv[], t_data *data);

/**
 * @brief
 *
 * @param meal
 * @return int
 */
int	ft_prepare_dinner(t_data *data);

int	ft_start_dinner(t_data *data, t_philosopher *philo);

void	*ft_routine(void *arg);

void	ft_monitoring(t_data *data, t_philosopher *philo);

int	ft_end_dinner(t_data *data, t_philosopher *philo);

int	ft_stopwatch(long long *value);

void	ft_elapsed_time_sleep(int	time_to_sleep, t_data *data);

void	ft_action_print(t_data *data, int id, char *string);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_bzero(void *s, size_t n);

void	*ft_memset(void *s, int c, size_t n);

#endif
