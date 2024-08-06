/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 10:18:35 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
bool philo_takes_fork(t_philo *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    if (philo->id % 2 == 0)
        better_sleep(30); // Stagger even philosophers

    time = (time_milliseconds() - philo->table->start_time);

    if (philo->id % 2 == 0) {
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
    } else 
    {
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);
    }

    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d has taken left fork\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);

    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d has taken right fork\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);

    return true;
}

bool philo_eat(t_philo *philosopher)
{
    t_philo *philo;
    long time;

    philo = (t_philo *)philosopher;
    time = (time_milliseconds() - philo->table->start_time);
    if (philo->table->stop == true)
        return false;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is eating\n", time ,philo->id);
    pthread_mutex_unlock(&philo->table->print);
    philo->last_eat = (time_milliseconds() - philo->table->start_time);
    better_sleep(philo->table->time_to_eat);
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
    if (philo->table->stop == true)
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



