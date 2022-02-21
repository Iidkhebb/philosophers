#include "philo_bonus.h"

void semaphore_init(t_profile *data)
{
    int i;
    
    i = 0;
    sem_unlink("fork");
    sem_unlink("pen");
    sem_unlink("philo_eated"); 
    data->fork = sem_open("fork", O_CREAT, 0644, data->nbr_philo);
    data->philo_eated = sem_open("philo_eated", O_CREAT, 0644, data->nbr_philo);
    data->pen = sem_open("pen", O_CREAT, 0644, 1);
    while (i < data->nbr_philo)
    {
        sem_wait(data->philo_eated);
        i++;
    }
    
}
void quit_process(t_profile *data)
{
    int i;
    i = 0;

    while (i < data->nbr_philo)
    {
        sem_wait(data->philo_eated);
        i++;
    }
    
}
void *checker_func(void *data)
{
    t_profile *list = (t_profile *)data;
    while (1)
    {
        if ((int)ft_timestamp_in_ms() - list->last_e > list->time_d)
        {
            sem_wait(list->pen);
            printf("\x1B[31m%d %d is dead\n\x1B[33m", ft_timestamp_in_ms(), list->ph_id);
            quit_process(data);
        }
        if (list->eating_fq > 0)
        {
            if (list->last_e_fq >= list->eating_fq)
                sem_post(list->philo_eated);
        }
    }
    
}

void philo_life(t_profile *data)
{
    while (1)
	{
        sem_wait(data->fork);
        sem_wait(data->pen);
	    printf("%d %d has taken a fork\n", ft_timestamp_in_ms(), data->ph_id);
        sem_post(data->pen);
        
		sem_wait(data->fork);
		sem_wait(data->pen);
		printf("%d %d has taken a fork\n", ft_timestamp_in_ms(), data->ph_id);
        sem_post(data->pen);

        sem_wait(data->pen);
		printf("%d %d is eating\n", ft_timestamp_in_ms(), data->ph_id);
        sem_post(data->pen);
		
        usleep(data->time_e * 1000);
		data->last_e = ft_timestamp_in_ms();
		data->last_e_fq++;
		
        sem_post(data->fork);
		sem_post(data->fork);

        sem_wait(data->pen);
		printf("%d %d is sleeping\n", ft_timestamp_in_ms(), data->ph_id);
		sem_post(data->pen);
		usleep(data->time_s * 1000);

		sem_wait(data->pen);
		printf("%d %d is thinking\n", ft_timestamp_in_ms(), data->ph_id);
		sem_post(data->pen);
	}
}


void main_logic(t_profile *data)
{
    pthread_t checker;
    pthread_create(&checker, NULL, &checker_func, data);
    philo_life(data);
}

t_pid *process_init(t_profile *data, char **av)
{
    int loop;
    int pid;
    t_pid *pid_list;

    pid_list = NULL;
    loop = 0;
    get_args(data, av);
    semaphore_init(data);
    while (loop < data->nbr_philo)
    {
        data->ph_id = loop + 1;
        loop++;
        pid = fork();
        if (pid == 0)
            main_logic(data);
        ft_lstadd_back(&pid_list, ft_lstnew(pid_list, pid));
        // usleep(90);
    }
    return pid_list;
}

void list_free(t_pid *list)
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

void kill_process(t_pid *pid_list, t_profile *data)
{
    t_pid *save_addr;
    int i;

    i = 0;
    while (i < data->nbr_philo)
    {
        sem_wait(data->philo_eated);
        i++;
    }
    save_addr = pid_list;
    while (pid_list)
    {
        kill(pid_list->pid, SIGQUIT);
        pid_list = pid_list->next;
    }
    list_free(save_addr);
}

int main(int ac, char *av[])
{
	t_profile *data;
    
    if (ac != 1)
    {
        data = (t_profile *)malloc(sizeof(t_profile));
        kill_process(process_init(data, av), data);
    }
    else
        ft_how_use();
    return 0;
}
