#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	r;

	i = 0;
	sign = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = (str[i] - 48) + (r * 10);
		i++;
	}
	return (r * sign);
}

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
