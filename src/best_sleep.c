/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:42:16 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/02 14:54:54 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *better_sleep(long time)
{
    long start;
    long end;

    start = time_milliseconds();
    end = start + time;
    while (time_milliseconds() < end)
        usleep(1);
    return (NULL);
}