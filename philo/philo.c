/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:16:01 by jeandrad          #+#    #+#             */
/*   Updated: 2024/07/31 16:44:23 by jeandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Main function
int	main(int argc, char *argv[])
{
	//Check if the number of arguments is correct
	//Pass to parse function
	(void) argv;
	parse(argc, argv);	

	return (0);
}
