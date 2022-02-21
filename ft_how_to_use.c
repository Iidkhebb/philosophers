/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_to_use.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:44 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 21:19:20 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_how_use(void)
{
	printf("\x1B[34m HOW TO USE : \n\x1B[37m");
	printf("\x1B[32m number_of_philosophers | time_to_die | time_to_eat |");
	printf(" time_to_sleep |[number_of_times_each_ \
philosopher_must_eat]\n\x1B[37m");
	return ;
}

void	*extra(t_profile *list)
{
	pthread_mutex_lock(list->pen);
	printf("\x1B[31m%d %d is dead\n\x1B[33m", ft_timestamp_in_ms(), list->ph_id);
	return (NULL);
}
