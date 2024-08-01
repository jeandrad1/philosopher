/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:24:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 12:25:44 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Function to initialize the philosopher
static bool init_philo (t_philo *philo, int i)
{
    philo->id = i + 1;
    philo->left_fork = philo->id;
    philo->right_fork = i;
    philo->eat_count = 0;
    philo->last_eat = 0;
    philo->is_dead = false;
    philo->thread = i;
    return (SUCCESS);
}

// Function to initialize all philosophers
bool init_all_philo(t_philo *philo, t_table *table)
{
    int i;
    int philo_count;

    i = 0;
    philo_count = table->philo_count;
    printf("Init all philo begins\n");
    printf("philo_count: %d\n", philo_count);
    while (i < philo_count)
    {
        if(!init_philo(&philo[i], i))
            return (FAILURE);
        i++;
    }
    philo[0].right_fork = philo_count;
    printf("Init all philo ends\n");
    return (SUCCESS);
}