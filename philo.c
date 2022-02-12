# include "philo.h"

void checker_thread(t_profile *list)
{
	pthread_t	checker;

	pthread_create(&checker, NULL, &philo_checker, list);
	pthread_join(checker ,NULL);

	return ;
}

void main_logic(t_profile *list)
{
	ft_lstlast(list)->next = list;
	thread_create(list);
	checker_thread(list);
	join_threads(list);
	pthread_mutex_destroy(&list->fork);
}

int main(int ac, char *av[])
{
	t_profile	*list;
	t_profile	*data;
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
		main_logic(list);
	}
	else
		ft_how_use();
	return (0);
}
