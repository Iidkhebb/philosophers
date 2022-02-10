# include "philo.h"

void *philo_logic(void *args)
{
	t_profile *data = (t_profile *)args;
	int i = 0;

	while (1)
	{
		int time =  ft_timestamp_in_ms();
		if (pthread_mutex_lock(&data->fork) == 0 && pthread_mutex_lock(&data->next->fork) ==0)
		{
			printf("\x1B[32m%d %d has taken a fork\n\x1B[37m", ft_timestamp_in_ms(), data->ph_id);
			printf("%d %d is eating\n", ft_timestamp_in_ms(), data->ph_id);
			usleep(data->time_e*1000);
			data->time_e = ft_timestamp_in_ms();
		}
		else
		{
			pthread_mutex_unlock(&data->fork);
			pthread_mutex_unlock(&data->next->fork);
		}
		pthread_mutex_unlock(&data->fork);
		pthread_mutex_unlock(&data->next->fork);

		printf("%d %d is sleeping\n", ft_timestamp_in_ms(), data->ph_id);
		usleep(data->time_s*1000);

		data->time_s = ft_timestamp_in_ms();

		printf("%d %d is thinking\n", ft_timestamp_in_ms(), data->ph_id);
		if ((int)ft_timestamp_in_ms()  > data->time_d + data->time_e)
		{
			printf("philo ==>> %d << == is dead\n", data->ph_id);
			exit(0);
		}
	}
}
