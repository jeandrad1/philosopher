/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/02 10:29:50 by jeandrad         ###   ########.fr       */
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
	
	//Take out
	printf("philo_count: %d\n", table.philo_count);
	printf("time_to_die: %d\n", table.time_to_die);
	printf("time_to_eat: %d\n", table.time_to_eat);
	printf("time_to_sleep: %d\n", table.time_to_sleep);
	printf("eat_count: %d\n", table.eat_count);
	//Stop here
	
	philo = (t_philo *) malloc(table.philo_count * sizeof(t_philo));
	if (!init_all_philo(philo, &table))
		return (EXIT_FAILURE);
	
	// Take out
	int i = 0;
	while (i < table.philo_count)
	{
		printf("\nphilo_id: %d\n", philo[i].id);
		printf("left_fork: %p\n", (void *) &philo[i].left_fork);
		printf("right_fork: %p\n", (void *) &philo[i].right_fork);
		printf("eat_count: %d\n", philo[i].eat_count);
		printf("last_eat: %lld\n", philo[i].last_eat);
		i++;
	}
	// Stop here

	// Threads creation
	printf("Creating threads of the philosophers\n");
	printf("Dinner begins\n");

	if (!create_philo_threads(philo, &table))
		return (EXIT_FAILURE);
		
	// Philosophers try to eat like normal people
	if (!dinner_ends(philo))
		return (EXIT_FAILURE);
		
	//Free memory
	free(philo);
	
	return (EXIT_SUCCESS);
}
