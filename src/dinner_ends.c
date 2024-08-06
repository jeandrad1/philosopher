/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_ends.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 19:20:39 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void stop_all_threads(t_table *table)
// {
//     pthread_mutex_lock(&table->is_dead);
//     table->stop = true;
//     pthread_mutex_unlock(&table->is_dead);
// }

bool dinner_ends(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    pthread_join(table->control, NULL);       
    while (i < philo->table->philo_count)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FAILURE);
        i++;
    }
    printf("Dinner ends\n");
    return (SUCCESS);
}