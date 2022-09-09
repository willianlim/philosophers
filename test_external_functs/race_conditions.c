#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	mails = 0;

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 1000000)
		mails++;
}

int main(int argc, char *argv[])
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (2);
	if (pthread_join(t1, NULL))
		return (3);
	if (pthread_join(t2, NULL))
		return (4);
	printf("Number of mails: %d\n", mails);
	return (0);
}
