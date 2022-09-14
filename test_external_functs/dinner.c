# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <pthread.h>

pthread_t		philosopher[5];
pthread_mutex_t	chopstick[5];

void	*func(void *arg)
{
	int	n;
	int	sleeptime;

	n = (long)arg;
	pthread_mutex_lock(&chopstick[n]);
	pthread_mutex_lock(&chopstick[(n + 1) % 5]);
	printf("Philosopher %d is thinking\n", n);
	printf("Philosopher %d is eating \n", n);
	sleep(3);
	sleeptime = rand() % 10;
	pthread_mutex_unlock(&chopstick[n]);
	pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
	printf("Philosopher %d finished eating in %d seconds \n", n, sleeptime);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int	i;
	srand(time(NULL));

	i = -1;
	while (++i < 5)
		pthread_mutex_init(&chopstick[i], NULL);
	i = -1;
	while (++i < 5)
		pthread_create(&philosopher[i], NULL, (void *)func, (void *)(long)i);
	i = -1;
	while (++i < 5)
		pthread_join(philosopher[i], NULL);
	i = -1;
	while (++i < 5)
		pthread_mutex_destroy(&chopstick[i]);
	return (0);
}
