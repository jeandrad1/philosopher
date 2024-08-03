/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:24:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 13:22:28 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Function to initialize the philosopher
static bool init_philo (t_philo *philo, t_table *table, int i)
{
    philo->id = i + 1;
    if (philo->id != 1)
        philo->right_fork = &table->forks[i - 1];
    else
        philo->right_fork = &table->forks[table->philo_count - 1];
    philo->left_fork = &table->forks[i];
    philo->eat_count = 0;
    philo->last_eat = 0;
    philo->table = table;
    return (SUCCESS);
}

// Function to initialize all philosophers
bool init_all_philo(t_philo *philo, t_table *table)
{
    int i;
    int philo_count;

    i = 0;
    philo_count = table->philo_count;
    while (i < philo_count)
    {
        if(!init_philo(&philo[i], table, i))
            return (FAILURE);
        i++;
    }
    return (SUCCESS);
}