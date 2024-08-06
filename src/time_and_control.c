/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_and_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:48:59 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 18:48:29 by jeandrad         ###   ########.fr       */
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

	while(table->stop == false)
	{
		usleep(1000);
	}
	return (NULL);
}