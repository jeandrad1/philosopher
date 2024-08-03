/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/03 14:42:08 by jeandrad         ###   ########.fr       */
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
	
	philo = (t_philo *) malloc(table.philo_count * sizeof(t_philo));
	if (!init_all_philo(philo, &table))
		return (EXIT_FAILURE);
	
	// Threads creation
	if (!create_philo_threads(philo, &table))
		return (EXIT_FAILURE);
		
	// Philosophers ends the dinner
	if (!dinner_ends(philo))
		return (EXIT_FAILURE);
		
	//Free memory
	free(philo);
	
	return (EXIT_SUCCESS);
}
