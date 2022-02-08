# include "philo.h"

int ft_timestamp_in_ms()
{
	struct timeval current_time;
	static int current = 0;
	static int prv = 0;
	static int out = 0;

	gettimeofday(&current_time, NULL);

	if (!prv)
		prv = current_time.tv_usec;
	current = current_time.tv_usec;
	out += (current - prv);
	prv = current;

	return (out);
}

