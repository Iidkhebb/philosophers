# include "philo.h"

int nbr = 0;

// void *func(void *mutex)
// {
// 	pthread_mutex_lock((pthread_mutex_t *)mutex);
// 	int i = 0;
// 	while(i < 1000000)
// 	{
// 		i++;
// 		nbr++;
// 	}
// 	pthread_mutex_unlock((pthread_mutex_t *)mutex);
// 	return 0;
// }



int main(int ac, char *av[])
{
	t_args *args;
	t_args *rs = get_args(args, ac, av);

	if  (ac != 1)
	{

	}
	ft_how_use();
	return (0);
}

	// pthread_t one;
	// pthread_t two;
	// pthread_mutex_t mutex;
	// pthread_mutex_init(&mutex, NULL);
	// pthread_create(&one, NULL, &func, &mutex);
	// pthread_create(&two, NULL, &func, &mutex);
	// pthread_join(two, NULL);
	// pthread_join(one, NULL);
	// pthread_mutex_destroy(&mutex);
