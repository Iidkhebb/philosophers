/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidkhebb <iidkhebb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:58:02 by iidkhebb          #+#    #+#             */
/*   Updated: 2022/02/21 21:25:31 by iidkhebb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_pid	*ft_lstnew(int pid)
{
	t_pid	*new;

	new = (t_pid *)malloc(sizeof(t_pid));
	if (!(new))
		return (0);
	new->pid = pid;
	new->next = NULL;
	return (new);
}

t_pid	*ft_lstlast(t_pid *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_pid **lst, t_pid *new)
{
	t_pid	*last_node;

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

void	list_free(t_pid *list)
{
	t_pid	*tmp;

	if (!list)
		return ;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	list = NULL;
	return ;
}
