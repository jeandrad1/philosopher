/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/07 10:35:25 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool protected_print(t_philo philo, char *str)
{
    long time;

    time = time_milliseconds() - philo.table->start_time;
    pthread_mutex_lock(&philo.table->print);
    printf("\n%ld Philosopher %d %s\n", time, philo.id, str);
    pthread_mutex_unlock(&philo.table->print);
    return true;
}
    
bool philo_takes_fork(t_philo *philo)
{
    if (philo->id % 2 == 0)
        usleep(300); 

    pthread_mutex_lock(philo->left_fork);
    protected_print(*philo, "has taken left fork");
    pthread_mutex_lock(philo->right_fork);
    protected_print(*philo, "has taken right fork");
    
    return true;
}

bool philo_eat(t_philo *philo)
{
    if (philo->table->stop == true)
    {
        printf("Philosopher %d is full\n", philo->id);
        pthread_mutex_lock(&philo->table->eat);
        return false;
    }
    protected_print(*philo, "is eating");
    philo->last_eat = (time_milliseconds() - philo->table->start_time);
    philo->eat_count++;
    printf("Philosopher time to eat %d\n", philo->table->time_to_eat);
    usleep(philo->table->time_to_eat * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);

    return true;
}

bool philo_sleep(t_philo *philo)
{
    if (philo->table->stop == true)
        return false;
    protected_print(*philo, "is sleeping");
    usleep(philo->table->time_to_sleep);
    return true;
}
bool philo_think (t_philo *philo)
{
    protected_print(*philo, "is thinking");
    usleep(1000);
    return true;
}



