/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:33:08 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 19:24:17 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *philosopher_actions(void *arg)
{
    t_philo *philo = (t_philo *)arg;
//    pthread_mutex_lock(&philo->table->ready);
//    pthread_mutex_unlock(&philo->table->ready);
//    printf("Philosopher %d is ready\n", philo->id);
    while (philo->table->stop == false)
    {
        if (philo_takes_fork(philo) == false)
            break ;
        if (philo_eat(philo) == false)
            break ;
        if (philo_sleep(philo) == false)
            break ;
        if (philo_think(philo) == false)
            break ;
    }
    return (NULL);
}

static bool create_thread (t_philo *philo)
{
    if (pthread_create(&philo->thread, NULL, &philosopher_actions, philo) != 0)
        return (FAILURE);
    return (SUCCESS);
}

bool create_philo_threads(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    pthread_mutex_lock(&table->ready);
    table->start_time = time_milliseconds();
    while (i < table->philo_count)
    {
        if (!create_thread(&philo[i]))
            return (FAILURE);
        i++;
    }
    pthread_create(&table->control, NULL, &control, table);
    pthread_mutex_unlock(&table->ready);
    return (SUCCESS);
}