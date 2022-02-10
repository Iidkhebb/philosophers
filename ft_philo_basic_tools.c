# include "philo.h"

void ft_init(t_profile *data)
{
	data->nbr_philo = 0;
	data->time_d = 0;
	data->time_e = 0;
	data->time_s = 0;
}

void get_args(t_profile *data, int ac, char  *av[])
{
	ft_init(data);
	data->nbr_philo = ft_atoi(av[1]);
	data->time_d = ft_atoi(av[2]);
	data->time_e = ft_atoi(av[3]);
	data->time_s = ft_atoi(av[4]);
	if (av[5])
		data->eating_fq = ft_atoi(av[5]);
	return ;
}
