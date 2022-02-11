# include "philo.h"

int ft_timestamp_in_ms()
{
	struct timeval current_time;
	int current;
	static int prv = 0;
	int out;

	gettimeofday(&current_time, NULL);

	current = current_time.tv_sec * 1000;
	current += current_time.tv_usec / 1000;

	if (!prv)
		prv = current;
	out = (current - prv);
	return (out);
}
