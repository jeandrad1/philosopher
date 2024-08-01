/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:35:09 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 18:30:09 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *think (void *philosopher)
{
    t_philo *philo;

    philo = (t_philo *)philosopher;
//  pthread_mutex_lock(&philo->table->print);
    printf("\nPhilosopher %d is thinking\n", philo->id);
//  pthread_mutex_unlock(&philo->table->print);
    usleep(1000000);
    return NULL;
}
