/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:23 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 21:01:32 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checker_thread(t_profile *list)
{
	pthread_t	checker;

	pthread_create(&checker, NULL, &philo_checker, list);
	pthread_join(checker, NULL);
	return ;
}

void	main_logic(t_profile *list)
{
	ft_lstlast(list)->next = list;
	thread_create(list);
	checker_thread(list);
	join_threads(list);
	pthread_mutex_destroy(&list->fork);
}

void	list_free(t_profile *list)
{
	int			i;
	int			loop;
	t_profile	*tmp;

	if (!list)
		return ;
	i = 0;
	loop = list->nbr_philo;
	while (i < loop)
	{
		tmp = list->next;
		free(list);
		list = tmp;
		i++;
	}
	list = NULL;
	return ;
}

int	main(int ac, char *av[])
{
	t_profile		*list;
	t_profile		*data;
	int				count;
	pthread_mutex_t	pen;

	if (ac != 1)
	{
		data = (t_profile *)malloc(sizeof(t_profile));
		get_args(data, av);
		list = NULL;
		data->ph_id = 1;
		count = data->nbr_philo;
		while (count != 0)
		{
			ft_lstadd_back(&list, ft_lstnew(data, &pen));
			data->ph_id++;
			count--;
		}
		free(data);
		main_logic(list);
		list_free(list);
	}
	else
		ft_how_use();
	return (0);
}
