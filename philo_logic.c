/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:11 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 22:00:49 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_profile *data)
{
	data->nbr_philo = 0;
	data->time_d = 0;
	data->time_e = 0;
	data->time_s = 0;
	data->last_e = 0;
	data->eating_fq = 0;
	data->last_e = 0;
}

int	get_args(t_profile *data, char *av[])
{
	ft_init(data);
	data->nbr_philo = ft_atoi(av[1]);
	if (data->nbr_philo < 1)
		return (0);
	data->time_d = ft_atoi(av[2]);
	data->time_e = ft_atoi(av[3]);
	data->time_s = ft_atoi(av[4]);
	if (av[5])
		data->eating_fq = ft_atoi(av[5]);
	return (1);
}

void	unlock_mutex(t_profile *data)
{
	pthread_mutex_unlock(&data->fork);
	pthread_mutex_unlock(&data->next->fork);
}

void	print_fork_taken(t_profile *data)
{
	pthread_mutex_lock(&data->fork);
	pthread_mutex_lock(data->pen);
	printf("%d %d has taken a fork\n", ft_timestamp_in_ms(), data->ph_id);
	pthread_mutex_unlock(data->pen);
}

void	*philo_logic(void *args)
{
	t_profile	*data;

	data = (t_profile *)args;
	while (1)
	{
		print_fork_taken(data);
		pthread_mutex_lock(&data->next->fork);
		pthread_mutex_lock(data->pen);
		printf("%d %d has taken a fork\n", ft_timestamp_in_ms(), data->ph_id);
		pthread_mutex_unlock(data->pen);
		pthread_mutex_lock(data->pen);
		printf("%d %d is eating\n", ft_timestamp_in_ms(), data->ph_id);
		pthread_mutex_unlock(data->pen);
		usleep(data->time_e * 1000);
		data->last_e = ft_timestamp_in_ms();
		data->last_e_fq++;
		unlock_mutex(data);
		pthread_mutex_lock(data->pen);
		printf("%d %d is sleeping\n", ft_timestamp_in_ms(), data->ph_id);
		pthread_mutex_unlock(data->pen);
		usleep(data->time_s * 1000);
		pthread_mutex_lock(data->pen);
		printf("%d %d is thinking\n", ft_timestamp_in_ms(), data->ph_id);
		pthread_mutex_unlock(data->pen);
	}
}
