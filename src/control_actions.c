/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:53 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/07 16:53:57 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void check_stop(t_table *table)
{
    // long i;
    // long has_eaten;

    // has_eaten = 0;
    // while (table->stop == false)
    // {
    //     i = 0;
    //     has_eaten = 0;
	// 	while (i < table->philo_count)
	// 	{
	// 		if (table->philo[i].eat_count >= table->eat_max)
	// 			has_eaten++;
	// 		i++;
	// 	}
    //     if (has_eaten == table->philo_count)
    //     {
    //         table->stop = true;
    //         pthread_mutex_lock(&table->print);
    //         printf("Philosophers have eaten enough\n");
    //         pthread_mutex_unlock(&table->print);
    //     }
    // }
    // table->stop = true;

    int i;

    i = 0;

    while (i)
    if (table->stop == true)
        return ;
    long now ;
    now = (time_milliseconds() - table->start_time);

    if ((now - table->philo[i].last_eat) > table->time_to_die)
    {
        protected_print(table->philo[i], "died");
        pthread_mutex_lock(&table->is_dead);
        table->stop = true;
        pthread_mutex_unlock(&table->is_dead);
        return ;
    }
    return ;

}

void	*control(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
    //pthread_mutex_lock(&table->ready);
    pthread_mutex_lock(&table->ready);
	while(1)
	{
		check_stop(table);
        if (table->stop == true)
        {
            pthread_mutex_lock(&table->print);
            printf("Philosopher ends the dinner\n");
            pthread_mutex_unlock(&table->print);
            break ;
        }
        usleep(1000);
	}
    pthread_mutex_unlock(&table->ready);
	return (NULL);
}