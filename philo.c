# include "philo.h"

int main(int ac, char *av[])
{
	t_profile *list;
	t_profile *data;
	int count;
	int i = 0;

	data = (t_profile *)malloc(sizeof(t_profile));
	get_args(data, ac, av);
	list = NULL;
	data->ph_id = 1;
	count = data->nbr_philo;

	if  (ac != 1)
	{
		while (count != 0)
		{
			ft_lstadd_back(&list, ft_lstnew(data));
			data->ph_id++;
			count--;
		}
		ft_lstlast(list)->next = list;

		while (i < data->nbr_philo)
		{
			pthread_mutex_init(&list->fork, NULL);
			pthread_create(&list->thread_philo, NULL, &philo_logic, list);
			list = list->next;
			i++;
		}

		i = 0;

		while (i < data->nbr_philo)
		{
			pthread_join(list->thread_philo ,NULL);
			list = list->next;
			i++;
		}
		
		pthread_mutex_destroy(&list->fork);
	}
	else
		ft_how_use();

	free((t_profile *)data);
	//ft_lstclear(&list);

	return (0);
}
