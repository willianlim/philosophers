/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:31:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/20 17:08:28 by wrosendo         ###   ########.fr       */
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

struct s_rules;

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
	long long		last_time_to_eat;
	pthread_t		thread_id;
	pthread_t		monitoring_id;
	pthread_mutex_t	check_mutex;
	struct s_rules	*rules;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}t_philosopher;

typedef struct s_rules
{
	int				number_of_philo;
	int				number_of_eat_finish_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_per_philo;
	int				finish;
	long long		starting_stopwatch;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}t_rules;

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @param meal
 * @return int
 */
int	ft_handling_input(int argc, char *argv[], t_rules *rules);

/**
 * @brief
 *
 * @param meal
 * @return int
 */
int	ft_prepare_dinner(t_rules *rules);

int	ft_start_dinner(t_rules *rules);

void	*ft_routine(void *arg);

void	*ft_monitoring(void *arg);

void	*ft_monitoring_each_must_each(void *arg);

int	ft_end_dinner(t_rules *rules);

int	ft_stopwatch(long long *value);

void	ft_elapsed_time_sleep(int	time_to_sleep, t_rules *rules);

void	ft_action_print(t_philosopher *philo, char *string);

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

int	ft_strcmp(const char *s1, const char *s2);

#endif
