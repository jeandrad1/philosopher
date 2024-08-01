/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/01 11:27:51 by jeandrad         ###   ########.fr       */
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
	
	//Take out
	int i = 1;
	while (i <= table.philo_count)
	{
		printf("\nphilo_id: %d\n", philo[i].id);
		printf("left_fork: %d\n", philo[i].left_fork);
		printf("right_fork: %d\n", philo[i].right_fork);
		printf("eat_count: %d\n", philo[i].eat_count);
		printf("last_eat: %lld\n", philo[i].last_eat);
		printf("is_dead: %d\n\n", philo[i].is_dead);
		i++;
	}
	//Stop here

	return (EXIT_SUCCESS);
}
