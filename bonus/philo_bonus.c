/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:55 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 21:24:22 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	main_logic(t_profile *data)
{
	pthread_t	checker;

	pthread_create(&checker, NULL, &checker_func, data);
	philo_life(data);
}

t_pid	*process_init(t_profile *data, char **av)
{
	int		loop;
	int		pid;
	t_pid	*pid_list;

	pid_list = NULL;
	loop = 0;
	get_args(data, av);
	semaphore_init(data);
	while (loop < data->nbr_philo)
	{
		data->ph_id = loop + 1;
		loop++;
		pid = fork();
		if (pid == 0)
			main_logic(data);
		ft_lstadd_back(&pid_list, ft_lstnew(pid));
		if (data->ph_id % 2 != 0)
			usleep(100);
	}
	return (pid_list);
}

int	main(int ac, char *av[])
{
	t_profile	*data;

	if (ac != 1)
	{
		data = (t_profile *)malloc(sizeof(t_profile));
		kill_process(process_init(data, av), data);
	}
	else
		ft_how_use();
	return (0);
}
