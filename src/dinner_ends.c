/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_ends.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/08 12:38:34 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// This functions ends the dinner
// It joins the control thread and the philosopher threads
bool dinner_ends(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    //pthread_mutex_lock(&table->print);
    //pthread_mutex_unlock(&table->print);
    pthread_join(table->control, NULL);
    while (i < philo->table->philo_count)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}