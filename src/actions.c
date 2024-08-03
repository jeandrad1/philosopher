/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 19:00:31 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void *philo_takes_fork(void *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    if (philo->table->dead == true)
        return NULL;
    time = time_milliseconds() - philo->table->start_time;
    pthread_mutex_lock(philo->left_fork);
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d has taken a fork\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d has taken a fork\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    return NULL;
}

void *philo_eat(void *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    time = time_milliseconds() - philo->table->start_time;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is eating\n", time ,philo->id);
    pthread_mutex_unlock(&philo->table->print);
    philo->last_eat = (time_milliseconds() - philo->table->start_time) * 1000;
    usleep(philo->table->time_to_eat * 1000);
    return NULL;
}

void *philo_sleep(void *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    time = time_milliseconds() - philo->table->start_time;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is sleeping\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    usleep(philo->table->time_to_sleep * 1000);
    return NULL;
}
void *philo_think (void *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    time = time_milliseconds() - philo->table->start_time;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is thinking\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    usleep(10000);
    return NULL;
}



