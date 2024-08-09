/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:33:08 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/09 15:27:30 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This is the rutine of the philosophers
// during the dinner and the condition to stop
static void *philosopher_actions(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    
    if (philo->id % 2 == 0)
        better_sleep(1000); 
    while (!protected_death(philo))
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

// This function creates the thread for the philosopher
// and checks if it was created correctly
static bool create_thread (t_philo *philo)
{
    if (pthread_create(&philo->thread, NULL, &philosopher_actions, philo) != 0)
        return (FAILURE);
    return (SUCCESS);
}

// This function creates the threads for the philosophers and the control thread
// It also locks the ready mutex to make sure all the threads are created at the same time
// It also sets the start time of the dinner
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