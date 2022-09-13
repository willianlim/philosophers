#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;

	index = *(int *)arg;
	printf("%d ", primes[index]);
	free(arg);
}

int	main(int argc, char *argv[])
{
	int			i;
	int			*a;
	pthread_t	thread[10];

	i = -1;
	while (++i < 10)
	{
		a = (int *)malloc(sizeof(int));
		*a = i;
		if (pthread_create(&thread[i], NULL, &routine, a))
			perror("Failed to create thread");
	}
	i = -1;
	while (++i < 10)
		if (pthread_join(thread[i], NULL))
			perror("Failed to create join");
	puts("");
	return (0);
}
