/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:33:08 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 18:28:51 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void *philosopher_actions(void *arg)
{
    t_philo *philo = (t_philo *)arg;
//    pthread_mutex_lock(&philo->table->ready);
//    pthread_mutex_unlock(&philo->table->ready);
    while (true)
    {
        philo_takes_fork(philo);
        philo_eat(philo);
        philo_sleep(philo);
        philo_think(philo);
    }
    return (NULL);
}

static bool create_thread (t_philo *philo)
{

    philo->table->start_time = time_milliseconds();
    if (pthread_create(&philo->thread, NULL, &philosopher_actions, philo) != 0)
        return (FAILURE);
    return (SUCCESS);
}

bool create_philo_threads(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    pthread_mutex_lock(&table->ready);
    pthread_create(&table->control, NULL, &control, table);
    while (i < table->philo_count && table->dead != true)
    {
        if (!create_thread(&philo[i]))
            return (FAILURE);
        i++;
    }
    pthread_mutex_unlock(&table->ready);
    return (SUCCESS);
}