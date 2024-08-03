/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:48:59 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 18:31:55 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_milliseconds(void)
{
	struct timeval	tv;
	long	time_ms;

	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time_ms);
}

void	*control(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;

	while(true)
	{
		if (table->philo_count == 1)
		{
			usleep(table->time_to_die * 1000);
			pthread_mutex_lock(&table->print);
			printf("\n%ld Philosopher 1 died\n", time_milliseconds() - table->start_time);
			pthread_mutex_unlock(&table->print);
			table->dead = true;
			return (NULL);
		}
		{
			table->dead = true;
		}
	}
	return (NULL);
}