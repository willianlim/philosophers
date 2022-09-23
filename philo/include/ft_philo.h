/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:31:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/09/22 22:05:11 by wrosendo         ###   ########.fr       */
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

struct	s_rules;

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
	long			last_time_to_eat;
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
	long			starting_stopwatch;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}t_rules;

//============================================================================//
//================================ Aux Library ===============================//
//============================================================================//

void	ft_action_print(t_philosopher *philo, char *string);
int		ft_atoi(const char *nptr);
void	ft_elapsed_time_sleep(int time_to_sleep);
void	ft_take_fork(t_philosopher *philo);
void	ft_eat(t_philosopher *philo);
void	ft_put_fork(t_philosopher *philo);
void	ft_sleep(t_philosopher *philo);
void	ft_think(t_philosopher *philo);
void	*ft_monitoring_each_must_each(void *arg);
void	*ft_monitoring(void *arg);
void	*ft_routine(void *arg);
int		ft_stopwatch(long *value);
int		ft_strcmp(const char *s1, const char *s2);

//============================================================================//
//================================ Aux Library ===============================//
//============================================================================//

int		ft_end_dinner(t_rules *rules);
int		ft_start_dinner(t_rules *rules);

//============================================================================//
//================================ Aux Library ===============================//
//============================================================================//

int		ft_handling_input(int argc, char *argv[], t_rules *rules);
int		ft_prepare_dinner(t_rules *rules);

#endif
