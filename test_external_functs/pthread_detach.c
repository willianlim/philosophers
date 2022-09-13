#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

# define THREAD_NUM 2

void	*routine()
{
	sleep(1);
	printf("Finished execution\n");
}

int main(int argc, char *argv[])
{
	int			i;
	pthread_t	threads[THREAD_NUM];

	i = -1;
	while (++i < 4)
	{
		if (pthread_create(&threads[i], NULL, &routine, NULL))
			perror("Failed to create thread");
		pthread_detach(threads[i]);
	}
	i = -1;
	while (++i < 4)
	{
		if (pthread_join(threads[i], NULL))
			perror("Failed to join thread");
	}
	return (0);
}
