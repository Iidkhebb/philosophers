/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:57:40 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 21:16:58 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_profile	*ft_lstnew(t_profile *data, pthread_mutex_t *pen)
{
	t_profile	*new;

	new = (t_profile *)malloc(sizeof(t_profile));
	if (!(new))
		return (0);
	new->ph_id = data->ph_id;
	new->nbr_philo = data->nbr_philo;
	new->time_d = data->time_d;
	new->time_e = data->time_e;
	new->time_s = data->time_s;
	new->eating_fq = data->eating_fq;
	new->next = NULL;
	new->pen = pen;
	return (new);
}

t_profile	*ft_lstlast(t_profile *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_profile **lst, t_profile *new)
{
	t_profile	*last_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
