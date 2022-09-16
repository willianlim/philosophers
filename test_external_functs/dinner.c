# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <pthread.h>

# include <string.h>

pthread_t		philosopher[5];
pthread_mutex_t	chopstick[5];

void	*func(void *arg)
{
	int	i;
	int	iteration;
	int	n;
	int	sleeptime;

	i = -1;
	iteration = 2;
	n = *(long *)arg;
	while (++i < 2)
	{
		pthread_mutex_lock(&chopstick[n]);
		pthread_mutex_lock(&chopstick[(n + 1) % 5]);
		printf("\nBegin eating: %d with forks %d and %d", n, n, (n + 1) % 5);
		sleep(3);
		printf("\nFinish eating: %d", n);
		sleeptime = rand() % 10;
		pthread_mutex_unlock(&chopstick[n]);
		pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
		printf("\nThinking: %d", n);
	}
	free(arg);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	*arg;
	srand(time(NULL));

	i = -1;
	while (++i < 5)
		pthread_mutex_init(&chopstick[i], NULL);
	i = -1;
	while (++i < 5)
	{
		arg = (int *)malloc(sizeof(int));
		*arg = i;
		pthread_create(&philosopher[i], NULL, (void *)func, arg);
	}
	i = -1;
	while (++i < 5)
		pthread_join(philosopher[i], NULL);
	i = -1;
	while (++i < 5)
		pthread_mutex_destroy(&chopstick[i]);
	return (0);
}
