#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

long long	timeval_to_milisec(struct timeval time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	main(void)
{
	struct timeval	start;
	struct timeval	stop;

	gettimeofday(&start, NULL);
	sleep(1);
	gettimeofday(&stop, NULL);
	printf("%lld\n", timeval_to_milisec(stop) - timeval_to_milisec(start));
	return (0);
}
