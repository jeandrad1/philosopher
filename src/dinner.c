/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 15:11:10 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool dinner(t_philo *philo, t_table *table)
{
    int i;

    i = 0;
    while (i < table->philo_count)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}