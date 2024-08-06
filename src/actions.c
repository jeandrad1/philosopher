/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 16:06:26 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
bool philo_takes_fork(t_philo *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    if (philo->id % 2 == 0)
        usleep(30); 
    
    // if(philo->table->stop == true)
    //     return false;
    
    time = (time_milliseconds() - philo->table->start_time);
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d has taken left fork\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);

    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d has taken right fork\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);

    return true;
}

bool philo_eat(t_philo *philo)
{
    long time;

    time = (time_milliseconds() - philo->table->start_time);
    // if (philo->table->stop == true)
    //     {
    //         printf("philo_eat 1\n");
    //         return false;
    //     };
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is eating\n", time ,philo->id);
    pthread_mutex_unlock(&philo->table->print);
    philo->eat_count++;
    philo->last_eat = (time_milliseconds() - philo->table->start_time);
    usleep(philo->table->time_to_eat);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);

    return true;
}

bool philo_sleep(t_philo *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    time = time_milliseconds() - philo->table->start_time;
    if(philo->table->stop == true)
         return false;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is sleeping\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    usleep(philo->table->time_to_sleep);
    return true;
}
bool philo_think (t_philo *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    time = time_milliseconds() - philo->table->start_time;
    if (philo->table->stop == true)
        return false;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is thinking\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    usleep(100);
    return true;
}



