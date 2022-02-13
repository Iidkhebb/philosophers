# include "philo.h"

int eat_count(t_profile *list)
{
	if (list->eating_fq > 0)
	{
		if (list->last_e_fq >= list->eating_fq)
			return 1;
	}
	return 0;
}

void *philo_checker(void *args)
{
	t_profile *list = (t_profile *)args;
	int i;
	int count;

	while (1)
	{
		i = 0;
		count = 0;
		while (i < list->nbr_philo)
		{
			count += eat_count(list);
			if ((int)ft_timestamp_in_ms() - list->last_e > list->time_d)
			{
				pthread_mutex_lock(list->pen);
				printf("\x1B[31m%d %d is dead\n\x1B[33m", ft_timestamp_in_ms(), list->ph_id);
				return NULL;
			}
			list = list->next;
			i++;
		}
		if (count >= list->nbr_philo)
			break ;
	}
	pthread_mutex_lock(list->pen);
	return NULL;
}

void mutex_init(t_profile *list)
{
	int i;

	i = 0;
	while (i < list->nbr_philo)
	{
		pthread_mutex_init(list->pen, NULL);
		pthread_mutex_init(&list->fork, NULL);
		list = list->next;
		i++;
	}
}

void thread_create(t_profile *list)
{
	int i;

	i = 0;
	mutex_init(list);
	while (i < list->nbr_philo)
	{
		pthread_create(&list->thread_philo, NULL, &philo_logic, list);
		usleep(90);
		list = list->next;
		i++;
	}
}

void join_threads(t_profile *list)
{
	int i;

	i = 0;
	while (i < list->nbr_philo)
	{
		pthread_detach(list->thread_philo);
		list = list->next;
		i++;
	}
}
