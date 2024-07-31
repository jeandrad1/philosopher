/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 19:14:49 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Main function
int	main(int argc, char *argv[])
{
	t_table	table;
	
	if(parse(argc, argv))
		return (EXIT_FAILURE);
	if(init_table(&table, argc, argv))
		return (EXIT_FAILURE);
	printf("philo_count: %d\n", table.philo_count);
	printf("time_to_die: %d\n", table.time_to_die);
	printf("time_to_eat: %d\n", table.time_to_eat);
	printf("time_to_sleep: %d\n", table.time_to_sleep);
	printf("eat_count: %d\n", table.eat_count);
	
	return (EXIT_SUCCESS);
}
