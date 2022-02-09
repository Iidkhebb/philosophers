# include "philo.h"

void ft_init(t_args *args)
{
	args->nbr_philo = 0;
	args->time_d = 0;
	args->time_e = 0;
	args->time_s = 0;
}

t_args *get_args(t_args *args, int ac, char  *av[])
{
	ft_init(args);
	args->nbr_philo = ft_atoi(av[1]);
	args->time_d = ft_atoi(av[2]);
	args->time_e = ft_atoi(av[3]);
	args->time_s = ft_atoi(av[4]);
	if (av[5])
		args->eating_fq = ft_atoi(av[5]);
	return (args);
}
