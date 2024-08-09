/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:31:33 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/09 15:40:35 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	protected_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->is_dead);
	if (philo->table->stop == true)
	{
		pthread_mutex_unlock(&philo->table->is_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->is_dead);
	return (0);
}

void	ft_free(t_table *table)
{
	free(table->forks);
	free(table->philo);
}
