/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timestamp_in_ms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:29 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 21:05:36 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_timestamp_in_ms(void)
{
	struct timeval	current_time;
	int				current;
	static int		prv = 0;
	int				out;

	gettimeofday(&current_time, NULL);
	current = current_time.tv_sec * 1000;
	current += current_time.tv_usec / 1000;
	if (!prv)
		prv = current;
	out = (current - prv);
	return (out);
}
