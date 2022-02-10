# include "philo.h"

void	ft_lstadd_front(t_profile **lst, t_profile *new)
{
	new->next = *lst;
	*lst = new;
}


t_profile	*ft_lstnew(t_profile *data)
{
	t_profile	*new;

	new = (t_profile *)malloc(sizeof(t_profile));
	if (!(new))
		return (0);

	new->ph_id = data->ph_id;
	new->time_d = data->time_d;
	new->time_e = data->time_e;
	new->time_s = data->time_s;
	new->eating_fq = data->eating_fq;

	new->next = NULL;
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

void	ft_lstdelone(t_profile *lst)
{
	if (!(lst))
		return ;
	free(lst);
}

void	ft_lstclear(t_profile **lst)
{
	t_profile	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}