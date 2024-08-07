/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_ends.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/07 19:34:28 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void stop_all_threads(t_table *table)
// {
//     pthread_mutex_lock(&table->is_dead);
//     table->stop = true;
//     pthread_mutex_unlock(&table->is_dead);
// }


// This functions ends the dinner
// It joins the control thread and the philosopher threads
bool dinner_ends(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    printf("Entra en dinner ends\n");
    pthread_join(table->control, NULL);
    printf("Control thread has finished\n"); 
    while (i < philo->table->philo_count)
    {
        printf("Entra en philo join\n");
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FAILURE);
        i++;
        printf("Philosopher %d has finished\n", i);
    }
    printf("Dinner ends\n");
    return (SUCCESS);
}