/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:28:13 by jeandrad          #+#    #+#             */
/*   Updated: 2024/08/09 16:34:47 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Main function
// Has this parts:
// 1 Parse the arguments
// 2-> Initialize the table
// 3-> Initialize all the philosophers
// 4-> Create the threads
// 5-> Check if the dinner ends
// 6-> Free the philosophers
int	main(int argc, char *argv[])
{
	t_table	*table;

	if (!parse(argc, argv))
		return (EXIT_FAILURE);
	table = (t_table *)malloc(sizeof(t_table));
	if (!init_table(table, argc, argv))
		return (EXIT_FAILURE);
	table->philo = ft_calloc(table->philo_count, sizeof(t_philo));
	if (!init_all_philo(table->philo, table))
		return (EXIT_FAILURE);
	if (!create_philo_threads(table->philo, table))
		return (EXIT_FAILURE);
	if (!dinner_ends(table->philo, table))
		return (EXIT_FAILURE);
	ft_free(table);
	return (EXIT_SUCCESS);
}
