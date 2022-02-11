# include "philo.h"

void unlock_mutex(t_profile *data)
{
	pthread_mutex_unlock(&data->fork);
	pthread_mutex_unlock(&data->next->fork);
}


void *philo_logic(void *args)
{
	t_profile *data = (t_profile *)args;

	while (1)
	{
		pthread_mutex_lock(&data->fork);
		printf("\x1B[32m%d %d has taken a fork\n\x1B[37m", ft_timestamp_in_ms(), data->ph_id); // eating
		pthread_mutex_lock(&data->next->fork);
		printf("\x1B[32m%d %d has taken a fork\n\x1B[37m", ft_timestamp_in_ms(), data->ph_id); // eating
		printf("%d %d is eating\n", ft_timestamp_in_ms(), data->ph_id);
		usleep(data->time_e * 1000);
		data->last_e = ft_timestamp_in_ms();
		data->last_e_fq++;
		
		unlock_mutex(data);

		printf("%d %d is sleeping\n", ft_timestamp_in_ms(), data->ph_id); // sleeping
		usleep(data->time_s * 1000);

		printf("%d %d is thinking\n", ft_timestamp_in_ms(), data->ph_id); // thinking
	}
}
