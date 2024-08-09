/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:47:53 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/09 16:13:28 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_eat(t_table *table)
{
	long	i;
	long	has_eaten;

	i = 0;
	has_eaten = 0;
	while (i < table->philo_count && table->eat_max != -1)
	{
		if (table->philo[i].eat_count >= table->eat_max)
			has_eaten++;
		i++;
		if (has_eaten == table->philo_count)
		{
			pthread_mutex_lock(&table->print);
			printf("\n\nAll philosophers have eaten enough\n\n");
			pthread_mutex_unlock(&table->print);
			pthread_mutex_lock(&table->is_dead);
			table->stop = true;
			pthread_mutex_unlock(&table->is_dead);
			break ;
		}
		better_sleep(100);
	}
}

void	check_stop(t_table *table)
{
	int		i;
	long	now;

	i = 0;
	now = (time_milliseconds() - table->start_time);
	while (i < table->philo_count)
	{
		if (table->stop == true)
			return ;
		if ((now - table->philo[i].last_eat) > table->time_to_die)
		{
			protected_print(&table->philo[i], "died");
			pthread_mutex_lock(&table->is_dead);
			table->stop = true;
			pthread_mutex_unlock(&table->is_dead);
			return ;
		}
		i++;
	}
}

void	*control(void *arg)
{
	t_table	*table;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->ready);
	if (table->philo_count == 1)
	{
		check_eat(table);
		return (NULL);
	}
	while (1)
	{
		check_eat(table);
		check_stop(table);
		if (table->stop == true)
		{
			break ;
		}
		better_sleep(100);
	}
	pthread_mutex_unlock(&table->ready);
	return (NULL);
}
