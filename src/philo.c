/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/06 11:25:33 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Main function
int	main(int argc, char *argv[])
{
	t_table	table;
	t_philo	*philo;

	philo = NULL;
	
	if (!parse(argc, argv))
		return (EXIT_FAILURE);
	if (!init_table(&table, argc, argv))
		return (EXIT_FAILURE);
	
	philo = ft_calloc(table.philo_count, sizeof(t_philo));
	if (!init_all_philo(philo, &table))
		return (EXIT_FAILURE);
	
	// Threads creation
	if (!create_philo_threads(philo, &table))
		return (EXIT_FAILURE);
		
	// Philosophers ends the dinner
	if (!dinner_ends(philo, &table))
		return (EXIT_FAILURE);
		
	//Free memory
	free(philo);
	
	return (EXIT_SUCCESS);
}
