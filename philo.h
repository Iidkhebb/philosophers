#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_args
{
	int	nbr_philo;
	int	time_d;
	int	time_e;
	int time_s;
	int	eating_fq;
}	t_args;


int		ft_timestamp_in_ms();
t_list	*ft_lstnew(void *content);
size_t	ft_strlen(const char *str);
void	ft_how_use(void);
int		ft_atoi(const char *str);
t_args	*get_args(t_args *args, int ac, char  *av[]);
void	ft_init(t_args *args);
#endif
