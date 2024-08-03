/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_ends.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 13:13:11 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool dinner_ends(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->table->philo_count)
    {
        if (pthread_join(philo[i].thread, NULL) != 0)
            return (FAILURE);
        i++;
    }       
    printf("Dinner %d ends\n", philo[i].id);
    return (SUCCESS);
}