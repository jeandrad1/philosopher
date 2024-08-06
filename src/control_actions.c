/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:53 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 18:23:07 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_stop(t_table *table)
{
    long i;
    long has_eaten;

    has_eaten = 0;
    while (table->stop == false)
    {
        i = 0;
        has_eaten = 0;
		while (i < table->philo_count)
		{
			if ((&table->philo[i])->eat_count >= table->eat_max)
				has_eaten++;
			i++;
		}
        if (has_eaten == table->philo_count)
        {
            table->stop = true;
            pthread_mutex_lock(&table->is_dead);
            printf ("All philosophers have eaten %i times\n", table->eat_max); 
            pthread_mutex_unlock(&table->is_dead);
        }
    }
    table->stop = true;
}

void	*control(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
    pthread_mutex_lock(&table->ready);
	while(1)
	{
		//check_stop(table);
        if (table->stop == true)
        {
            pthread_mutex_lock(&table->is_dead);
            printf("Philosopher ends the dinner\n");
            pthread_mutex_unlock(&table->is_dead);
            break ;
        }
	}
	return (NULL);
}