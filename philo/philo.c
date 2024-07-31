/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 15:26:10 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Main function
int	main(int argc, char *argv[])
{
	//Check if the number of arguments is correct
	//Pass to parse function
	(void) argv;
	
	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments\n");
		return 1;
	}
	
	return (0);
}
