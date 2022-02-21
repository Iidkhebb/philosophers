#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_profile
{
	int		nbr_philo;
	int		ph_id;
	int		time_d;
	int		time_e;
	int		time_s;
	int		eating_fq;
	int		last_e;
	int		last_e_fq;

	sem_t	*fork;
	sem_t	*philo_eated;
	sem_t	*pen;

}	t_profile;

typedef struct s_pid
{
	int				pid;
	struct s_pid	*next;

}t_pid;

int		ft_timestamp_in_ms();
t_pid	*ft_lstnew(int pid);
void	ft_lstadd_back(t_pid **lst, t_pid *new);
void	ft_how_use(void);
int		ft_atoi(const char *str);
void	get_args(t_profile *data, char  *av[]);
void	ft_init(t_profile *data);
void	semaphore_init(t_profile *data);
void	quit_process(t_profile *data);
void	*checker_func(void *data);
void	philo_life(t_profile *data);
void	main_logic(t_profile *data);
t_pid	*process_init(t_profile *data, char **av);
void	list_free(t_pid *list);
void	kill_process(t_pid *pid_list, t_profile *data);
#endif
