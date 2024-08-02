/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/02 11:28:30 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_think (void *philosopher)
{
    t_philo *philo;
    long    time;

    philo = (t_philo *)philosopher;
    time = time_milliseconds();
    pthread_mutex_lock(&philo->table->print);
    printf("\n %ld Philosopher %d is thinking\n", time,philo->id);
    pthread_mutex_unlock(&philo->table->print);
    usleep(100000);
    return NULL;
}

void *philo_eat(void *philosopher)
{
    t_philo *philo;
    long time;

    time = time_milliseconds();
    philo = (t_philo *)philosopher;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is eating\n", time ,philo->id);
    pthread_mutex_unlock(&philo->table->print);
    philo->last_eat = time_milliseconds();
    usleep(100000);
    return NULL;
}

void *philo_sleep(void *philosopher)
{
    t_philo *philo;
    long time;

    time = time_milliseconds();
    philo = (t_philo *)philosopher;
    pthread_mutex_lock(&philo->table->print);
    printf("\n%ld Philosopher %d is sleeping\n", time, philo->id);
    pthread_mutex_unlock(&philo->table->print);
    usleep(100000);
    return NULL;
}

