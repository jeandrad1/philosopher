/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:24:48 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 11:55:32 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool init_philo (t_philo *philo, int i)
{
    philo->id = i;
    philo->left_fork = i;
    philo->right_fork = i - 1;
    philo->eat_count = 0;
    philo->last_eat = 0;
    philo->is_dead = false;
    philo->thread = i;
    return (SUCCESS);
}
bool init_all_philo(t_philo *philo, t_table *table)
{
    int i;
    int philo_count;

    i = 1;
    philo_count = table->philo_count;
    printf("Init all philo begins\n");
    printf("philo_count: %d\n", table->philo_count);
    while (i <= philo_count)
    {
        if(!init_philo(&philo[i], i))
            return (FAILURE);
        i++;
    }
    philo[1].right_fork = philo_count;
    philo[philo_count].right_fork = 1;
    printf("Init all philo ends\n");
    return (SUCCESS);
}