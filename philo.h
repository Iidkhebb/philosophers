#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


int		ft_timestamp_in_ms();
t_list	*ft_lstnew(void *content);
#endif
