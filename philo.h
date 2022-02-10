#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_profile
{
	int	nbr_philo;
	int	ph_id;
	int	time_d;
	int	time_e;
	int time_s;
	int	eating_fq;
	int	last_e;
	int last_e_fq;

	struct s_profile *next;
	pthread_t thread_philo;
	pthread_mutex_t fork;
} t_profile;

int			ft_timestamp_in_ms();
t_profile	*ft_lstnew(t_profile *data);
void		ft_lstadd_front(t_profile **lst, t_profile *new);
void		ft_lstadd_back(t_profile **lst, t_profile *new);
size_t		ft_strlen(const char *str);
void		ft_how_use(void);
int			ft_atoi(const char *str);
void		get_args(t_profile *data, char  *av[]);
void		ft_lstclear(t_profile **lst);
void		ft_lstdelone(t_profile *lst);
void		ft_init(t_profile *data);
t_profile	*ft_lstlast(t_profile *lst);

void *philo_checker(void *args);
void *philo_logic(void *args);
void thread_create(t_profile *list);
void join_threads(t_profile *list);

#endif
