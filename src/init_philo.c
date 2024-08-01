/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:24:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 11:28:08 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool init_philo (t_philo *philo, int i)
{
    philo->id = i;
    philo->left_fork = i;
    philo->right_fork = i;
    philo->eat_count = i;
    philo->last_eat = i;
    philo->is_dead = false;
    philo->thread = i;
    return (SUCCESS);
}
bool init_all_philo(t_philo *philo, t_table *table)
{
    int i;

    i = 1;
    printf("Init all philo begins\n");
    printf("philo_count: %d\n", table->philo_count);
    while (i <= table->philo_count)
    {
        printf("philo %i initializing\n", i);  
        if(!init_philo(&philo[i], i))
            return (FAILURE);
        printf("philo %i initialized\n", i);
        i++;
    }
    printf("Init all philo ends\n");
    return (SUCCESS);
}