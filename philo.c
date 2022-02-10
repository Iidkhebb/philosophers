# include "philo.h"

int main(int ac, char *av[])
{
	t_profile	*list;
	t_profile	*data;
	pthread_t	checker;
	int			count;

	if  (ac != 1)
	{
		data = (t_profile *)malloc(sizeof(t_profile));
		get_args(data, av);
		list = NULL;
		data->ph_id = 1;
		count = data->nbr_philo;

		while (count != 0)
		{
			ft_lstadd_back(&list, ft_lstnew(data));
			data->ph_id++;
			count--;
		}
		free(data);
		ft_lstlast(list)->next = list;
		thread_create(list);
		if (list->eating_fq > 0)
		{
			pthread_create(&checker, NULL, &philo_checker, list);
			pthread_join(checker ,NULL);
		}
		join_threads(list);
		pthread_mutex_destroy(&list->fork);
	}
	else
	{
		ft_how_use();
	}

	//free((t_profile *)data);
	//ft_lstclear(&list);
	return (0);
}
