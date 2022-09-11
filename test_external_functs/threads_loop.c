#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char *argv[])
{
	int			i;
	pthread_t	threads[4];

	i = -1;
	pthread_mutex_init(&mutex, NULL);
	while (++i < 4)
	{
		if (pthread_create(&threads[i], NULL, &routine, NULL))
		{
			perror("Failed to create thread\n");
			return (1);
		}
		printf("Thread %d has started\n", i);
	}
	i = -1;
	while (++i < 4)
	{
		if (pthread_join(threads[i], NULL))
			return (2);
		printf("Thread %d has finished execution\n", i);
	}

	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}
