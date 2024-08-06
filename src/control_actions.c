/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:53 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 14:15:07 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_stop(t_table *table)
{
    long i;
    long has_eaten;

    i = 0;
    has_eaten = 0;
    while (table->start == false)
        ;
    while (i < table->philo_count && table->stop == false)
    {
        if (table->philo[i].eat_count >= table->eat_max)
            has_eaten++;
        if (has_eaten == table->philo_count)
            table->stop = true;
        i++;
    }
    
    table->stop = true;
}

void	*control(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;

	while(table->stop == false)
	{
		check_stop(table);
	}
	return (NULL);
}