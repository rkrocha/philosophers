#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void	*routine(void *arg)
{
	printf("Hello, thread %ld\n", (long)arg);
	sleep((long)arg);
	printf("Goodbye, thread %ld\n", (long)arg);
	return (NULL);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, routine, (void *)1) != 0)
		printf("Thread 1 - create error\n");
	if (pthread_create(&t2, NULL, routine, (void *)2) != 0)
		printf("Thread 2 - create error\n");

	if (pthread_join(t1, NULL) != 0)
		printf("Thread 1 - join error\n");
	if (pthread_join(t2, NULL) != 0)
		printf("Thread 2 - join error\n");
	// pthread_detach(t2);
	return (0);
}
