/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:33:08 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 15:40:59 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool create_thread (t_philo *philo)
{
    if (pthread_create(&philo->thread, NULL, &think, &philo) != 0)
        return (FAILURE);
    return (SUCCESS);
}

bool create_philo_threads(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_count)
    {
        if (!create_thread(&philo[i]))
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}