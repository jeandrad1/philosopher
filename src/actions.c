/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/02 11:10:43 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *think (void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    pthread_mutex_lock(&philo->table->print);
    printf("\nPhilosopher %d is thinking\n", philo->id);
    pthread_mutex_unlock(&philo->table->print);
    usleep(100000);
    return NULL;
}

void *eat(void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
    pthread_mutex_lock(&philo->table->print);
    printf("\nPhilosopher %d is eating\n", philo->id);
    pthread_mutex_unlock(&philo->table->print);
    philo->last_eat = time_milliseconds();
    usleep(100000);
    return NULL;
}

