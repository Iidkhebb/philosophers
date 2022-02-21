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
        sem_post(data->philo_eated);
        i++;
    }
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
	free(data);
    while (pid_list)
    {
        kill(pid_list->pid, SIGQUIT);
        pid_list = pid_list->next;
    }
    list_free(save_addr);
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
        usleep(500);
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
