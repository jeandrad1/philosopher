/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:42:16 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 13:39:05 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *better_sleep(long time)
{
    long start;
    long end;

    start = time_milliseconds();
    end = (start + time) * 1000;
    while (time_milliseconds() < (end / 1000))
        usleep(1000);
    return (NULL);
}