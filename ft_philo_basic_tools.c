# include "philo.h"

void ft_init(t_profile *data)
{
	data->nbr_philo = 0;
	data->time_d = 0;
	data->time_e = 0;
	data->time_s = 0;
	data->last_e = 0;
	data->eating_fq = 0;
}

void get_args(t_profile *data, char  *av[])
{
	ft_init(data);
	data->nbr_philo = ft_atoi(av[1]);
	data->time_d = ft_atoi(av[2]);
	data->time_e = ft_atoi(av[3]);
	data->time_s = ft_atoi(av[4]);
	if (av[5])
		data->eating_fq = ft_atoi(av[5]);
}

void *philo_checker(void *args)
{
	t_profile *list = (t_profile *)args;
	int i = 0;
	int count = 0;

	while (1)
	{
		while (i < list->nbr_philo)
		{
			if (list->eating_fq > 0)
			{
				if (list->last_e_fq >= list->eating_fq)
				{
					count++;
				}
			}
			if ((int)ft_timestamp_in_ms() - list->last_e > list->time_d)
			{
				printf("%d %d is dead\n", ft_timestamp_in_ms(), list->ph_id);
				exit(0);
			}
			list = list->next;
			i++;
		}
		if (count >= list->nbr_philo)
		{
			break ;
		}
		i = 0;
		count = 0;
	}
	printf("ALL EATED\n");
	exit(0);
}
void mutex_init(t_profile *list)
{
	int i;

	i = 0;
	while (i < list->nbr_philo)
	{
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
		// pthread_mutex_init(&list->fork, NULL);
		pthread_create(&list->thread_philo, NULL, &philo_logic, list);
		usleep(100);
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
		pthread_join(list->thread_philo ,NULL);
		list = list->next;
		i++;
	}
}
