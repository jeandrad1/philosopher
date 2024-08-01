/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 18:13:03 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool dinner(t_philo *philo)
{
    int i;

    i = 0;
    printf("Dinner begins\n");
    while (i < philo->table->philo_count)
    {
        printf("Philosopher %d is thinking\n", philo[i].id);
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}