# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

// https://linuxhint.com/gettimeofday_c_language/#:~:text=The%20gettimeofday()%20function%20gets,%2C%201970%20(Unix%20Epoch).

int	main()
{
	int				i;
	struct timeval	start;
	struct timeval	stop;

	i = -1;
	while (++i < 100)
	{
		gettimeofday(&start, NULL);
		printf("Antes em milisegundos: %ld\n", start.tv_usec / 1000);
		printf("sleep.\n");
		sleep(3);
		gettimeofday(&stop, NULL);
		printf("Depois em milisegundos: %ld\n", stop.tv_usec / 1000);
		printf("Diferença em milisecundos: %ld\n\n", stop.tv_usec / 1000 - \
		start.tv_usec / 1000);
	}
	return (0);
}
