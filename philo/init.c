/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:39:46 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 15:49:16 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo(t_philo *philo, int max_philos)
{
    int i;

    i = 1;
    while (i <= max_philos)
    {
        philo->id = i;
    }
    philo->eat_count = 0;
    philo->last_eat = 0;
    philo->is_dead = false;
}