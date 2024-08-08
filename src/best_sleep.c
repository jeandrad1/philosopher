/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:42:16 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/08 10:43:29 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *better_sleep(long time)
{
	long	sleep_start;
	long	elapsed;

	sleep_start = time_milliseconds() * 1000;
	while ((time_milliseconds() * 1000) - sleep_start < time)
	{
		//if (check_finish_dinner(table))
		//	return (1);
		elapsed = time - ((time_milliseconds() * 1000) - sleep_start);
		if (elapsed > 1000)
			usleep(500);
		else
		{
			while ((time_milliseconds() * 1000) - sleep_start < time)
				;
		}
	}
	return (0);
}